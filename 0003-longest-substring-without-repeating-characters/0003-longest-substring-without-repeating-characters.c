int lengthOfLongestSubstring(char* s) {
    int right = 0 , left = 0 , maxLen = 0;
    int length = strlen(s);

    typedef struct{
        int key;
        int value;
        UT_hash_handle hh;
    }HashEntry;

    HashEntry *map = NULL;
    HashEntry *find,*entry;

    while(right < length){

        int ch = (int)s[right];
        HASH_FIND_INT(map, &ch, find);

        if(find != NULL && find -> value >= left){
            left = find -> value + 1;
        }

        if(find != NULL && find -> value < left){
            find -> value = right;
        }

        else{
            entry = malloc(sizeof(HashEntry));
            entry -> key = ch;
            entry -> value = right;

            HASH_ADD_INT(map,key,entry);
        }

        if(maxLen < right - left + 1){
            maxLen = right - left +1;
        }

        right++;
    }
    return maxLen;
}