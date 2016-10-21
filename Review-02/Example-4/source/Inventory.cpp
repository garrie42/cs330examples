#include <utility>
#include "Inventory.h"

// Allow the compiler to define the remaining 
// comparison operators
using namespace std::rel_ops;

/**
 * 
 */
Inventory::Node::Node()
    :data( Item(0, "Air"), 0 )
{
    this->next = nullptr;
}

/**
 *
 */
Inventory::Node::Node( ItemStack s )
    :data(s)
{
    this->next = nullptr;
}

/**
 *
 */
Inventory::Inventory(){
    this->first    = nullptr;
    this->last     = nullptr;
    this->slots    = 10;
    this->occupied = 0;

    //std::cout << Node().data << "\n";
}

/**
 *
 */
Inventory::Inventory( int n ){
    this->first    = nullptr;
    this->last     = nullptr;
    this->slots    = n;
    this->occupied = 0;
}

/**
 * 
 */
Inventory::Inventory( const Inventory &src ){
    this->first    = nullptr;
    this->last     = nullptr;

    this->slots    = src.slots;
    this->occupied = 0;

    for( Node *it = src.first; it!= nullptr; it = it->next ){
        this->addItems( it->data );
    }
}

/**
 *
 */
Inventory::~Inventory(){
    Node *it = first;

    while( it!= nullptr ){
        Node *next = it->next;
        delete it;

        it = next;
    }
}

/**
 *
 */
bool Inventory::addItems( ItemStack stack ){
    // Check for matching node
    Node* it = this->first;

    while (it != nullptr) {
        if (stack == it->data) {
            //Merge stack into it->data
            (it->data).addItems(stack.size());

            return true;
        }
        it = it->next;
    }

    // Check if full
    if (occupied >= slots) {
        return false;
    }

    // Invoke the appendNode private member function
    this->appendNode(stack);
    return true;       
}

void Inventory::display( std::ostream &outs ) const{
    outs << " -Used " << occupied << " of " << slots << " slots" << "\n";

    for( Node *it = first; it!= nullptr; it = it->next ){
        outs << "  " << it->data << "\n";
    }
}

Inventory& Inventory::operator=( const Inventory &rhs ){
    if( this != &rhs ){
        // Create copy of rhs
        Inventory copy(rhs);

        // Swap each copy.attribute with corresponding this->attribute
        std::swap(this->first, copy.first);
        std::swap(this->last, copy.last);

        std::swap(this->occupied, copy.occupied);
        std::swap(this->slots, copy.slots);

        // Rely on implict destructor call
    }

    return *this;
}

/**
 *
 */
void Inventory::appendNode(ItemStack stack) 
{
    Node* newNode = nullptr;   

    // Handle the case where the first node is added
    if( this->first == nullptr){
        newNode = new Node( stack );

        this->first = newNode;
        this->last = newNode;

        this->occupied++;
        return; 
    }

    // Add the node (all conditions have been checked)
    newNode = new Node( stack );
    (this->last)->next = newNode;
    this->last = newNode;   

    this->occupied++; 
}