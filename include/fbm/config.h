#ifndef FBM_CONFIG_INCLUDED
#define FBM_CONFIG_INCLUDED


    #ifdef FBM_DLL
        #ifdef _WIN32
            #define FBM_EXPORT __declspec(dllexport)
        #else
            #define FBM_EXPORT __attribute__((visibility ("default")))
        #endif // _WIN32
    #else
        #define FBM_EXPORT
    #endif // FBM_DLL


#endif //FBM_CONFIG_INCLUDED
