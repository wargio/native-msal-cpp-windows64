project('msalruntime', 'c', version: '0.14.0')

# Do some sanity checking so that meson can fail early instead of at final link time
if not (host_machine.system() == 'windows' and host_machine.cpu_family() == 'x86_64')
  error('This wrap of msalruntime is a binary wrap for x64_64 Windows, and will not work on your system')
endif

cc = meson.get_compiler('c')

deps = cc.find_library('msalruntime', dirs : [meson.current_source_dir() / 'build_resources'])

msalruntime_dep = declare_dependency(
  dependencies : deps,
  include_directories : include_directories('build_resources'))

meson.override_dependency('msalruntime', msalruntime_dep)

# we must install the dll in the same directory to allow the executable to work.
install_data(meson.current_source_dir() / 'pymsalruntime' / 'msalruntime.dll', install_dir: get_option('prefix') / 'bin')
