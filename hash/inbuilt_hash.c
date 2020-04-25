Any C structure can be stored in a hash table using uthash. Just add a UT_hash_handle to the structure and choose one or more fields in your structure to act as the key. Then use these macros to store, retrieve or delete items from the hash table.
Example 1. Adding an item to a hash.
#include "uthash.h"

struct my_struct {
    int id;            /* we'll use this field as the key */
    char name[10];
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_struct *users = NULL;

void add_user(struct my_struct *s) {
    HASH_ADD_INT( users, id, s );
    // users is the hash table
    // id is the key
    // s is the pointer to the struct being added
    // malloc s, set the key and value and then send it
}

Example 2. Looking up an item in a hash.
struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );
    // users is the hash table
    // user_id is the item key to look up
    // s is the output variable which points to the struct with the given key
    return s;
}

Example 3. Deleting an item from a hash.
void delete_user(struct my_struct *user) {
    HASH_DEL( users, user);
    //users is the hash table
    //user is the pointer to the struct we want to remove
}

Have used it in two sums in the array section. refer for how to use
more on this at :https://troydhanson.github.io/uthash/userguide.html
