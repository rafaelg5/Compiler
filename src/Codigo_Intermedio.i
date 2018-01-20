************ CODIGO INTERMEDIO **************
 inst        op      arg1      arg2      dest
    0     label                          suma
    1         +         a         b        t1
    2    return        t1                    
    3     label                       endsuma
    4     label                    expresiones
    5         +         1         a        t2
    6         *   punto.x   c[0][1]        t3
    7      push         a                    
    8      push  3.000000                    
    9      call      suma                  t4
   10         /        t3        t4        t5
   11         -        t2        t5        t6
   12         =        t6                b[0]
   13         *    "algo"  3.000000        t7
   14         +        t7         1        t8
   15         =        t8                b[1]
   16     label                    endexpresiones
   17     label                        logica
   18         *         1         4        t9
   19         -         b        t9       t10
   20       if<         a       t10        28
   21      goto                            22
   22      if>=         b         a        24
   23      goto                            27
   24         +         c         5       t11
   25      if<=         a       t11        28
   26      goto                            27
   27      goto                            28
   28         +         1         3       t12
   29         %         2         5       t13
   30         -       t12       t13       t14
   31         =       t14                   a
   32     label                     endlogica
   33     label                          fors
   34         =         1                   b
   35         =         0                   a
   36         =         1                   a
   37       if<         a        10        46
   38      goto                            51
   39         +         a         1       t15
   40         =       t15                   a
   41      push         a                    
   42      push         b                    
   43      call      suma                 t16
   44         =       t16                   b
   45      goto                            37
   46         +         b         a       t17
   47         +       t17         1       t18
   48         =       t18                   b
   49     print         b                    
   50      goto                            39
   51    return                              
   52     label                       endfors
   53     label                        whiles
   54         =         0                   a
   55         =         1                   b
   56         +         a         b       t19
   57       if<       t19        10        59
   58      goto                            65
   59         *         a         2       t20
   60         =       t20                   a
   61         -         b         1       t21
   62         =       t21                   b
   63      goto                            65
   64      goto                            56
   65    return                              
   66     label                     endwhiles
   67     label                      dowhiles
   68         =         0                   b
   69         +         a         1       t22
   70         =       t22                   a
   71         +         b         5       t23
   72       if<         a       t23        69
   73      goto                            74
   74    return                              
   75     label                    enddowhiles
   76     label                      switches
   77         +         a         3       t24
   78      if==       t24         1        80
   79      goto                            82
   80     print         a                    
   81      goto                            88
   82      if==       t24         2        84
   83      goto                            86
   84     print         b                    
   85      goto                            88
   86     print         c                    
   87      goto                            88
   88     print         d                    
   89    return                              
   90     label                    endswitches
