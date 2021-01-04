#ifndef __SRC_SORT_H
#define __SRC_SORT_H

#define DATA_TYPE_MAP(XX)                           \
    XX(int)                                         \
    XX(long)                                        \
    XX(float)                                       \
    XX(double)

#define SORT_ALG_MAP(XX, type)                      \
    XX(bubble, type)                                \
    XX(select, type)                                \
    XX(insert, type)                                \
    XX(shell, type)                                 \
    XX(merge, type)

#define SORT_ALG_DECLARE_GEN1(name, type)           \
    int sort_alg_##name##_##type(type *data,        \
                int size);

#define SORT_ALG_DECLARE_GEN2(type)                 \
    SORT_ALG_MAP(SORT_ALG_DECLARE_GEN1, type)

DATA_TYPE_MAP(SORT_ALG_DECLARE_GEN2)

#undef SORT_ALG_DECLARE_GEN1
#undef SORT_ALG_DECLARE_GEN2

#undef SORT_ALG_MAP

#ifndef UNDEF_DATA_TYPE_MAP_FLAG
#undef DATA_TYPE_MAP
#endif

#endif
