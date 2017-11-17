#ifndef CONFIG_H
#define CONFIG_H

//这是对于linux与window平台下建立库的导出方法

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #  if defined( OSG_LIBRARY_STATIC )
    #    define OSG_EXPORT
    #  elif defined( OSG_LIBRARY )
    #    define OSG_EXPORT   __declspec(dllexport)
    #  else
    #    define OSG_EXPORT   __declspec(dllimport)
    #  endif
#else
    #  define OSG_EXPORT
#endif

// string test
//    int a[10]={0};
//    int s=sizeof(a);
//    int *b=a;
//    s=sizeof(b);

//    s=sizeof(argv);
//    s=sizeof(*argv);

//    char** ptr=argv;
//        for(int i=0;i<argc;i++)
//        {

//        printf("== %s \n",*ptr);
//        while(**ptr !=NULL)
//        {

//            printf("    %c \n",*(*ptr)++);
//            //            (*ptr)++;

//        }
//        ptr++;
//    }

//    return 0;


#endif // CONFIG_H
