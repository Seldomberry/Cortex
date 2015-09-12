require 'rake/clean'

LOCAL ||= false

if LOCAL == true then
    TARGETPATH = "./.corto"
    TARGETDIR = TARGETPATH
else
    PACKAGEDIR = "packages/" + PACKAGE.gsub("::", "/")
    TARGETPATH = PACKAGEDIR 
end

TARGET = PACKAGE.split("::").last

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    ".corto/#{TARGET}__api.c" <<
    ".corto/#{TARGET}__wrapper.c" <<
    ".corto/#{TARGET}__meta.c" <<
    ".corto/#{TARGET}__load.c"

GENERATED_HEADERS ||= [] <<
    "include/#{TARGET}__api.h" <<
    "include/#{TARGET}__meta.h" <<
    "include/#{TARGET}__type.h"

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
    sh "mkdir -p .corto"
    sh "touch .corto/#{TARGET}__wrapper.c"
    ret = system "corto pp #{GENFILE} --scope #{PACKAGE} --prefix #{PREFIX} --lang c"
    if !ret then
        sh "rm include/#{TARGET}__type.h"
        abort "\033[1;31m[ build failed ]\033[0;49m"
    end
end

task :default => "include/#{TARGET}__type.h" do
    require "./.corto/dep.rb"

    # Delay running inherited tasks - we first need to run
    # code generation for us to know which source files
    # have to be compiled.
    require "#{ENV['CORTO_BUILD']}/component"
    Rake::Task["prebuild"].invoke
    Rake::Task["binary"].invoke
    Rake::Task["postbuild"].invoke
end

clobber_count = 1
clean_count = 1

task :clean do
    # Recursively call clean, prevent infinite recursion
    if clean_count == 1 then
        clean_count += 1
        Rake::Task["clean"].reenable
        require "#{ENV['CORTO_BUILD']}/component"
        Rake::Task["clean"].execute
        if File.exists?(".corto/dep.rb")
            sh "rake clean -f .corto/dep.rb" 
        end
    end
end

task :clobber do
    # Recursively call clobber, prevent infinite recursion
    if clobber_count == 1 then
        clobber_count += 1
        Rake::Task["clobber"].reenable
        require "#{ENV['CORTO_BUILD']}/component"
        Rake::Task["clobber"].execute
        if File.exists?(".corto/dep.rb")
            sh "rake clobber -f .corto/dep.rb" 
        end
    end
end

if File.exists? "test" then
    COMPONENTS ||=[] << "test"
end

require "#{ENV['CORTO_BUILD']}/subrake"
