project('physics-engine', 'c')

files = [
  'src/main.c'
]

raylib_dep = dependency('raylib')
include_dirs = include_directories('include')

executable('physics-engine', files, include_directories: [include_dirs], dependencies: [raylib_dep])
