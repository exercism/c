Dir.mkdir("build") unless Dir.exist?("build")
Dir.mkdir("src") unless Dir.exist?("src")

PROJECT_CEEDLING_ROOT = "../vendor/ceedling"
load "#{PROJECT_CEEDLING_ROOT}/lib/ceedling.rb"

Ceedling.load_project

task :default => %w[ test:all ]
