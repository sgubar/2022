#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"

long reallocateInternalStorage(Storage *, int requestedCount);

Storage *createStorage(long preservedCount){
    Storage *array = (Storage *)malloc(sizeof(Storage));

    if(NULL != array){
        array -> count = (preservedCount > 0) ? preservedCount : 1;
        array -> storage = (Circle **)malloc(sizeof(Circle *) * array -> count);
        bzero(array -> storage, sizeof(Circle *) * array -> count);
    }

    return array;
}

void deleteStorage(Storage *s){
    if (NULL != s){
        if (NULL != s -> storage){
            free(s -> storage);
        }
    }

    free(s);
}

int setCircleByIndex(Storage *s, Circle *value, int index){
    if(NULL == s || index < 0){
        return StorageIndexError;
    }

    if (index > s -> count){
        if (StorageIndexError == reallocateInternalStorage(s, index + 1)){
            return StorageIndexError;
        }

    }

    s -> storage[index] = value;
    return index;
}

Circle *getCircleByIndex(Storage *s, int index){
    if(NULL == s || index < 0 || index >= s -> count){
        return NULL;
    }

    return s -> storage[index];
}

void printStorage(Storage *s){
    if(s == NULL){
        return ;
    }

    for(long i = 0; i < s -> count; i++){
        if (s -> storage[i] != NULL){
            printCircle(s -> storage[i]);
        }
        else{
            printf("NULL");
        }

        if (i < (s -> count -1)){
            printf(", ");
        }
    }

    printf("\n");
}

long countStorage(Storage *s){
    if (s == NULL){
        return StorageIndexError;
    }

    return s -> count;
}

long reallocateInternalStorage(Storage *s, int requestedCount){
    if (s -> count >= requestedCount){
        return s -> count;
    }

    int count = requestedCount * 2;
    Circle **storage = (Circle **)malloc(sizeof(Circle *) * count);

    if(storage == NULL){
        return StorageIndexError;
    }

    bzero(storage, sizeof(Circle *) * count);
    memcpy(storage, s -> storage, sizeof(Circle *) * s->count);
    free(s -> storage);

    s -> storage = storage;
    s -> count = count;

    return count;
}
