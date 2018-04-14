#include <utility>
#include "Inventory.h"

// Allow the compiler to define the remaining
// comparison operators
using namespace std::rel_ops;

/**
 *
 */
Inventory::Node::Node()
    :data(Item(0, "Air"), 0)
{
    this->next = nullptr;
}

/**
 *
 */
Inventory::Node::Node(ItemStack s)
    :data(s)
{
    this->next = nullptr;
}

/**
 *
 */
Inventory::Inventory()
{
    this->head    = nullptr;
    this->tail     = nullptr;
    this->slots    = 10;
    this->occupied = 0;

    //std::cout << Node().data << "\n";
}

/**
 *
 */
Inventory::Inventory(int n)
{
    this->head    = nullptr;
    this->tail     = nullptr;
    this->slots    = n;
    this->occupied = 0;
}

/**
 *
 */
Inventory::Inventory(const Inventory &src)
{
    // Complete this method
    this->head    = nullptr;
    this->tail     = nullptr;   //this->slots    = n;
    this->occupied = 0;
    this->slots = src.slots;
///Using this wont make me transverse my list because I would require a next private member variable in Inventory.h
    /*// Start copy by transversing the src list
       /// start from the begin of the src
    Inventory* srcIt = src.head;
         ///then transver till the very end
    if(srcIt != nullptr)
    {
        ///copy data into src

    }
    srcIt->    ///couldnt find a next member
    */
   //So we will us the Node class to do the transversing
      /// Node* srcIT = src.head;   ///I believe you cant assign to different type.
        Node* this_it = this->head;  //star from the begin which is a nullptr
        Node* src_it = src.head; // start from the begining of the src list
                                //why not use Node* src_it = src->head

        while(src_it != nullptr)
        {

              this->addItemStackNoCheck(src_it->data);

            src_it = src_it->next;
        }

}

/**
 *
 */
Inventory::~Inventory()
{
    // Complete this method

     Node* it = nullptr;   ///used for transversing the linkedlist inventory
     Node* to_delete = nullptr;  /// used for deleting


     it = this->head;   ///get a grip on the starting point on the list

     while(it != nullptr)
     {
        to_delete = it;   ///set to point to the same thing as it

        it = it->next;   /// moving it a step ahead of to_delete

        delete to_delete;   /// perform any operation after traversing is safe, but this case lets delete

        to_delete = nullptr;   ///what does this line do? probably make to_delete empty
    }

}

/**
 *
 */
bool Inventory::isFull() const
{
    // If this is more than one line
    // in the form "return (boolean expression);"
    // you are overthinking the problem
    return (this->occupied == this->slots); // replace false with the appropriate expression
}

/**
 *
 */
void Inventory::display(std::ostream &outs) const
{
    outs << " -Used " << occupied << " of " << slots << " slots" << "\n";

    Node* it = head;
    while(it != nullptr){
        outs << "  " << it->data << "\n";

        it = it->next;
    }
}

/**
 *
 */
Inventory& Inventory::operator=(Inventory rhs)
{
    std::swap(*this, rhs);
    return *this;
}

/**
 *
 */
void swap(Inventory& lhs, Inventory& rhs)
{
    using std::swap;

    swap(lhs.head, rhs.head);
    swap(lhs.tail, rhs.tail);
    swap(lhs.slots, rhs.slots);
    swap(lhs.occupied, rhs.occupied);
}

/**
 *
 */
Inventory::Node* Inventory::findMatchingItemStackNode(const ItemStack& itemStack)
{
    // Complete this method
        Node * it_ = nullptr;
      //  Node * itemStack_it = nullptr;


         it_ = this->head;  //start from the beginning of the inventory list
          //  itemStack_it = itemStack.head;  //start from the beginning of the itemStack list
         while(it_ != nullptr )
         {
                if(it_->data == itemStack)
                    return it_;

                  it_ = it_->next;
         }

    // No match was found
    return nullptr;
}

/**
 *
 */
void Inventory::addItemStackNoCheck(ItemStack itemStack)
{
    // Complete this method
    ///this method appends new ItemStack to the list
    Node* new_itemStack = nullptr; /// create a new Itemstack that points to nothing

    new_itemStack = new Node (itemStack);  ///make it point to an ItemStack data

     ///first instance
        ///when ItemStack is empty - a nullptr
       if(this->occupied == 0)
       {
            this->head = new_itemStack;
            this->tail = new_itemStack;
       }
       else{   ///the start of the second instance  and other subsquent instances, when first instance as been made.
            (this->tail)->next = new_itemStack;
            this->tail = new_itemStack;

       }

       this->occupied++;  ///since we want to move to the next list. using occupied++
}
