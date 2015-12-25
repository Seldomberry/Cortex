require 'rake/clean'

LOCAL ||= false
INCLUDE ||= []

if LOCAL == true then
    TARGETPATH = "./.corto"
    TARGETDIR = TARGETPATH
    INCLUDE << "include"
else
    PACKAGEDIR = "packages/" + PACKAGE.gsub("::", "/")
    TARGETPATH = PACKAGEDIR
end

TARGET = PACKAGE.split("::").last

PP_PRELOAD ||= []
GENERATED_SOURCES ||= []
DEFINE ||= []
CFLAGS ||= []

DEFINE << "BUILDING_" + PACKAGE.gsub("::", "_").upcase
CFLAGS << "-fvisibility=hidden"

GENERATED_SOURCES <<
    ".corto/#{TARGET}__api.c" <<
    ".corto/#{TARGET}__wrapper.c" <<
    ".corto/#{TARGET}__meta.c" <<
    ".corto/#{TARGET}__load.c"

GENERATED_HEADERS ||= [] <<
    "include/#{TARGET}__api.h" <<
    "include/#{TARGET}__meta.h" <<
    "include/#{TARGET}__type.h" <<
    "include/#{TARGET}__interface.h"

PREFIX ||= TARGET

CHDIR_SET = true
Dir.chdir(File.dirname(Rake.application.rakefile))

GENFILE = Rake::FileList["#{PACKAGE.split("::").last}.*"][0]

file ".corto/packages.txt" do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/packages.txt"
end

file ".corto/components.txt" do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/components.txt"
end

file "include/#{TARGET}__type.h" => [GENFILE, ".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
    preload = PP_PRELOAD.join(" ")
    sh "mkdir -p .corto"
    sh "touch .corto/#{TARGET}__wrapper.c"
    if LOCAL or (`corto locate doc --generator` == "corto: generator 'doc' not found\n") then
        command = "corto pp #{preload} #{GENFILE} --scope #{PACKAGE} --prefix #{PREFIX} --lang c"
    else
        command = "corto pp #{preload} #{GENFILE} --scope #{PACKAGE} --prefix #{PREFIX} --lang c -g doc"
    end
    begin
      sh command
    rescue
      puts "\033[1;31mcommand failed: #{command}\033[0;49m"
      sh "rm include/#{TARGET}__type.h"
      abort()
    end
end

task :doc do
    verbose(false)
    if `corto locate corto::md` != "corto: package 'corto::md' not found\n" then
        if File.exists? "README.md" and not LOCAL then
            command = "corto pp README.md --scope #{PACKAGE} -g html"
            begin
                sh command
            rescue
                puts "\033[1;31mcommand failed: #{command}\033[0;49m"
                abort()
            end
        end
    end
end

task :default => ["include/#{TARGET}__type.h"]

task :postbuild => [:doc]

if File.exists? "./.corto/dep.rb"
    require "./.corto/dep.rb"
end

require "#{ENV['CORTO_BUILD']}/component"
require "#{ENV['CORTO_BUILD']}/subrake"
