import excons
import os
import sys


env = excons.MakeBaseEnv()

staticlib = (excons.GetArgument("fbm-static", 1, int) != 0)
prefix = (excons.GetArgument("fbm-prefix", "", str))

out_incdir = excons.OutputBaseDirectory() + "/include"
out_libdir = excons.OutputBaseDirectory() + "/lib"

defs = []
cppflags = " -Wno-unused-parameter"
if not staticlib:
    defs.append("FBM_DLL")


prjs = []


prjs.append({"name": prefix + "fbm",
             "type": "staticlib" if staticlib else "sharedlib",
             "alias": "fbm-libs",
             "defs": defs,
             "cppflags": cppflags,
             "incdirs": [out_incdir],
             "srcs": excons.glob("src/*.cpp") + excons.glob("src/*/*.cpp"),
             "symvis": "hidden",
             "install": {out_incdir + "/fbm": excons.glob("include/fbm/*")},
             "custom": []})


for test in excons.glob("test/*.cpp"):
    prjs.append({"name": os.path.splitext(os.path.basename(test))[0],
                 "type": "testprograms",
                 "alias": "fbm-tests",
                 "defs": defs,
                 "cppflags": cppflags,
                 "incdirs": [out_incdir],
                 "srcs": [test],
                 "libdirs": [out_libdir],
                 "libs": [prefix + "fbm"]})


def FbmName():
    name = prefix + "fbm"
    if sys.platform == "win32" and staticlib:
        name = "lib" + name

    return name


def FbmPath():
    name = FbmName()
    if sys.platform == "win32":
        libname = name + ".lib"
    else:
        libname = "lib" + name + (".a" if staticlib else excons.SharedLibraryLinkExt())

    return out_libdir + "/" + libname


def RequireFbm(env):
    env.Append(CPPPATH=[out_incdir])
    env.Append(LIBPATH=[out_libdir])
    excons.Link(env, FbmPath(), static=staticlib, force=True, silent=True)


excons.AddHelpOptions(libraw="""FBM OPTIONS
  fbm-static=0|1     : Toggle between static and shared library build [1]
  fbm-prefix=<str>   : Library name prefix. []""")


excons.DeclareTargets(env, prjs)

Export("FbmName FbmPath RequireFbm")
