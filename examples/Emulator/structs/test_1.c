#include <stdio.h>

// Define the structure with a single 'id' field
struct MyStruct {
    int id;
};

// Function to update the 'id' of a MyStruct instance
// It takes a pointer to the struct and the new id value
void update_id(struct MyStruct *s, int new_id) {
    s->id = new_id;
}

int main() {
    // Create an instance of MyStruct
    struct MyStruct my_instance;
    my_instance.id = 10; // Initial ID

    // Print the initial ID
    printf("Initial ID: %d\n", my_instance.id);

    // Update the ID using the function
    update_id(&my_instance, 20);

    // Print the updated ID
    printf("Updated ID: %d\n", my_instance.id);

    return 0;
}