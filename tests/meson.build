include_directories('../include')
src = files(
  'logger.cpp',
  '../src/Logger.cpp',
)
exec = executable('first_test', src, dependencies: deps)
test('testing logger', exec)

src = files(
  '../src/Game.cpp',
  'game.cpp',
)
exec = executable('second_test', src, dependencies: deps)
test('testing game init',exec)
