#define UNDEF_DATA_TYPE_MAP_FLAG
#include "sort.h"

// for bubble
#define SORT_ALG_GEN(type)                                      \
    int sort_alg_bubble_##type(type *data, int size)            \
    {                                                           \
        if (!data || size<=0)                                   \
        {                                                       \
            return -1;                                          \
        }                                                       \
        for (int i=1; i<size; i++)                              \
        {                                                       \
            for (int j=0; j<size-i; j++)                        \
            {                                                   \
                if (data[j] > data[j + 1])                      \
                {                                               \
                    type tmp = data[j];                         \
                    data[j] = data[j + 1];                      \
                    data[j + 1] = tmp;                          \
                }                                               \
            }                                                   \
        }                                                       \
        return 0;                                               \
    }

DATA_TYPE_MAP(SORT_ALG_GEN)
#undef SORT_ALG_GEN

// for select
#define SORT_ALG_GEN(type)                                      \
    int sort_alg_select_##type(type *data, int size)            \
    {                                                           \
        if (!data || size<=0)                                   \
        {                                                       \
            return -1;                                          \
        }                                                       \
        for (int i=0; i<size-1; i++)                            \
        {                                                       \
            int min_index = i;                                  \
            for (int j=i+1; j<size; j++)                        \
            {                                                   \
                if (data[j]< data[min_index])                   \
                {                                               \
                    min_index = j;                              \
                }                                               \
                if (min_index != i)                             \
                {                                               \
                    type tmp = data[i];                         \
                    data[i] = data[min_index];                  \
                    data[min_index] = tmp;                      \
                }                                               \
            }                                                   \
        }                                                       \
        return 0;                                               \
    }

DATA_TYPE_MAP(SORT_ALG_GEN)
#undef SORT_ALG_GEN

// for insert
#define SORT_ALG_GEN(type)                                      \
    int sort_alg_insert_##type(type *data, int size)            \
    {                                                           \
        if (!data || size<=0)                                   \
        {                                                       \
            return -1;                                          \
        }                                                       \
        for (int i=1; i<size; i++)                              \
        {                                                       \
            int pre_index = i - 1;                              \
            type current = data[i];                             \
            while (pre_index >=0 && current < data[pre_index])  \
            {                                                   \
                data[pre_index + 1] = data[pre_index];          \
                pre_index -= 1;                                 \
            }                                                   \
            data[pre_index + 1] = current;                      \
        }                                                       \
        return 0;                                               \
    }

DATA_TYPE_MAP(SORT_ALG_GEN)
#undef SORT_ALG_GEN

// for shell
#define SORT_ALG_GEN(type)                                      \
    int sort_alg_shell_##type(type *data, int size)             \
    {                                                           \
        if (!data || size<=0)                                   \
        {                                                       \
            return -1;                                          \
        }                                                       \
        int gap = size / 2;                                     \
        while (gap > 0)                                         \
        {                                                       \
            for (int i = gap; i<size; i++)                      \
            {                                                   \
                type current = data[i];                         \
                int pre_index = i - gap;                        \
                while (pre_index>=0 && data[pre_index]>current) \
                {                                               \
                    data[pre_index + gap] = data[pre_index];    \
                    pre_index -= gap;                           \
                }                                               \
                data[pre_index + gap] = current;                \
            }                                                   \
            gap /= 2;                                           \
        }                                                       \
        return 0;                                               \
    }

DATA_TYPE_MAP(SORT_ALG_GEN)
#undef SORT_ALG_GEN

// for merger
#define SORT_ALG_GEN(type)                                      \
    int sort_alg_merge_##type(type *data, int size)             \
    {                                                           \
        if (!data || size<=1)                                   \
        {                                                       \
            return -1;                                          \
        }                                                       \
        int middle = size / 2;                                  \
        return 0;                                               \
    }

DATA_TYPE_MAP(SORT_ALG_GEN)
#undef SORT_ALG_GEN

// undefine DATA_TYPE_MAP
#undef DATA_TYPE_MAP
#undef UNDEF_DATA_TYPE_MAP_FLAG
