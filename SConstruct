import excons
import os


env = excons.MakeBaseEnv()

staticlib = (excons.GetArgument("fbm-static", 1, int) != 0)

out_incdir = excons.OutputBaseDirectory() + "/include"
out_libdir = excons.OutputBaseDirectory() + "/lib"

defs = []
cppflags = " -Wno-unused-parameter"
if staticlib:
    defs.append("FBM_DLL")


prjs = []


prjs.append({"name": "fbm",
             "type": "staticlib" if staticlib else "fbm-shared",
             "def": defs + ["FBM_SAHRED"],
             "cppflags": cppflags,
             "incdirs": [out_incdir],
             "srcs": excons.glob("src/*.cpp") + excons.glob("src/*/*.cpp"),
             "symbis": "default",
             "install": {out_incdir + "/fbm": excons.glob("include/fbm/*")},
             "custom": []})


for test in excons.glob("test/*.cpp"):
    prjs.append({"name": os.path.splitext(os.path.basename(test))[0],
                 "type": "testprograms",
                 "def": defs,
                 "cppflags": cppflags,
                 "incdirs": [out_incdir],
                 "srcs": [test],
                 "libdirs": [out_libdir],
                 "libs": "fbm"})



excons.DeclareTargets(env, prjs)