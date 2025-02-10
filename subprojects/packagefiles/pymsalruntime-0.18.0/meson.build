project('pymsalruntime', 'c', version: '0.18.0')

cc = meson.get_compiler('c')

msalruntime_build_resources_dir = meson.current_source_dir() / 'build_resources'
msalruntime_pymsalruntime_dir = meson.current_source_dir() / 'pymsalruntime'
msalruntime_headers_dir = include_directories('build_resources')

if target_machine.system() == 'windows'
  # generate the lib file which is required by windows linker
  if target_machine.cpu_family() == 'x86_64'
    dllarch = 'x64'
    dllname = 'msalruntime'
  elif target_machine.cpu_family() == 'x86'
    dllarch = 'x86'
    dllname = 'msalruntime_x86'
  elif target_machine.cpu_family() == 'aarch64'
    dllarch = 'arm64'
    dllname = 'msalruntime_arm64'
  else
    error('This wrap of msalruntime does not support windows on ' + target_machine.cpu_family())
  endif

  libgen = run_command('msalruntime_gen_lib.bat', dllarch, dllname, check: true)
  libgen_out = (libgen.stdout().strip() + '\n' + libgen.stderr()).strip()
  message('msalruntime_gen_lib.bat output\n' + libgen_out)

  deps = cc.find_library(dllname, dirs : [msalruntime_pymsalruntime_dir])

  msalruntime_dep = declare_dependency(
    dependencies: deps,
    include_directories : msalruntime_headers_dir)

  dll_msalruntime = dllname + '.dll'
  install_data(msalruntime_pymsalruntime_dir / dll_msalruntime, install_dir: get_option('prefix') / 'bin')

elif target_machine.system() == 'darwin'
  if target_machine.cpu_family() == 'x86_64'
    libname = 'msalruntime_x86_64'
  elif target_machine.cpu_family() == 'aarch64'
    libname = 'msalruntime_arm64'
  else
    error('This wrap of msalruntime does not support darwin on ' + target_machine.cpu_family())
  endif

  deps = cc.find_library(libname, dirs : [msalruntime_pymsalruntime_dir])

  msalruntime_dep = declare_dependency(
    dependencies : deps,
    compile_args: ['-DMSAUTH_PLATFORM_MACOS=1'],
    include_directories : msalruntime_headers_dir)
  meson.override_dependency('msalruntime', msalruntime_dep)

  dylib_msalruntime = libname + '.dylib'
  install_data(meson.current_source_dir() / 'pymsalruntime' / dylib_msalruntime, install_dir: get_option('prefix') / 'bin')

else
  error('msalruntime does not support ' + target_machine.system() + ' yet')
endif
