#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 20

struct DataItem{
	int data;
	int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
	return key %SIZE;
}

struct DataItem *search(int key){
	
	// get the hash
	int hashIndex= hashCode(key);
	
	//move in arrray until an empty
	
	while (hashArray[hashIndex]!= NULL){
		if (hashArray[hashIndex]->key==key){
				return hashArray[hashIndex];
		}
		
		hashIndex++;
		hashIndex %= SIZE;
	
	}
	return NULL;
}

// insert item

void insert(int key , int data){
	 struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	 item->data=data;
	 item->key =key;
	 
	 // get hash
	 int hashIndex=hashCode(key);
	 while(hashArray[hashIndex]!=NULL && hashArray[hashIndex]-> key != -1){
	 	hashIndex++;
	 	hashIndex%= SIZE;
	 	
	 }
	
	hashArray[hashIndex]= item;
	
}

// delete item
struct DataItem* delete1(struct DataItem* item) {
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}


// ham display
void display(){
	int i=0;
	for (i=0;i<SIZE;i++){
		if (hashArray[i]!= NULL){
			printf ("( %d , %d )",hashArray[i]->key,hashArray[i]->data);
		}
		else{
			printf("   ~~~   ");
		}
	printf("\n");
	}
	
}

int main(){
	// contruct new DataItem 
	DataItem* dummyItem =(struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->key=-1;
	dummyItem->data=-1;
	
	// insert new  DataItem
	insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    display();
    item =search(37);
    if(item != NULL) {
      printf("Element found: %d\n", item->data);
    } else {
      printf("Element not found\n");
    }
    
    delete1(item);
    if(item != NULL) {
      printf("Element found: %d\n", item->data);
    } else {
      printf("Element not found\n");
   }
    
	return 1;
}
