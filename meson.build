project('gra', 'cpp',
  default_options: ['warning_level=3', 'cpp_std=c++20'])

EXECUTABLE_NAME='exec'

src = files(
  'src/main.cpp',
  'src/Game.cpp',
  'src/Logger.cpp'
  )

include_directories('include')

deps = [
  dependency('sdl2'),
  dependency('sdl2_image'),
  dependency('sdl2_ttf'),
  dependency('sdl2_mixer'),
  dependency('sdl2_net'),
  ]


executable(EXECUTABLE_NAME, src, dependencies: deps)
subdir('tests')
