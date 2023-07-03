#include "List.h"
#include "Dish.h"

List::List(){

    head = NULL;
    tail = NULL;

}

List::List(List& parent)
{
    head = NULL;
    tail = NULL;
    if (!parent.length())
        return;
    auto it = parent.begin();
    for (; it != parent.end(); ++it)
        this->insert((*it));
    this->insert((*it));
}

List::~List()
{
    clearAll();
}

/*void List::pushFront(Dish data){

    Node* tmp = new Node;
    tmp->data = data;


    if (head == NULL){
        tmp->prev = nullptr;
        tmp->next = nullptr;
        head = tmp;
        tail = tmp;
    }
    else{
        tmp->prev = nullptr;
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }

}

void List::pushBack(Dish data) {

    Node* tmp = new Node;
    tmp->data = data;

    if (head == NULL) {
        tmp->prev = nullptr;
        tmp->next = nullptr;
        head = tmp;
        tail = tmp;
    }
    else{
        tmp->next = nullptr;
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }

}*/
List::Node* List::find(Dish const data) const{

    Node* tmp = head;

    while (data.getName() != tmp->data.getName()){
        tmp = tmp->next;
    }

    return tmp;
}

/*void List::deletion(Dish data) {

    Node* tmp = find(data);

    if (tmp == head)
    {
        if (tail == tmp)
        {
            head = tail = nullptr;
        }
        else
        {
            head = tmp->next;
            head->prev = nullptr;
        }
    }
    else if (tmp == tail)
    {
        tail = tmp->prev;
        tail->next = nullptr;
    }
    else if(tmp)
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    delete tmp;
    tmp = nullptr;

}*/

int List::length() const {

    Node* marker;
    marker = head;
    int count;

    if (marker == NULL){
        return 0;
    }
    else {
        while (marker != nullptr) {
            count += 1;
            marker = marker->next;
        }
    }

    return count;

}

void List::clearAll() {

    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
    head = NULL;
    tail = NULL;

}

void List::display(){

    //Node* marker;
    auto marker = head;

    if (marker == NULL){
        std::cout << "List is empty\n";
    }
    else {
        while (marker != NULL) {
            std::cout << marker->data.getName() << " ";
            std::cout << marker->data.getCost() << " ";
            std::cout << marker->data.energyValue() << " ";
            std::cout << marker->data.getWeight() << " ";
            std::cout << marker->data.getContentProteins() << " ";
            std::cout << marker->data.getContentFibers() << " ";
            std::cout << marker->data.getContentFats() << " ";
            std::cout << marker->data.getContentCarbons() << " ";
            std::cout << marker->data.getContentAcids() << std::endl;
            marker = marker->next;
        }
    }
    std::cout << std::endl;
};

List::Iterator List::begin() const {
    return head;
}

List::Iterator List::end() const {
    return tail;
}

List::Iterator::Iterator(Node* first)
{
    cur = first;
}

List::Iterator::~Iterator() = default;

List::Iterator& List::Iterator::operator++()
{
    if (!cur)
        throw std::out_of_range("Broken iterator.");
    if (!cur->next)
        throw std::out_of_range(
                "Error during incrementation: iterator has run out of List.");
    cur = cur->next;
    return *this;
}

List::Iterator List::Iterator::operator++(int)
{
    auto tmp(this->cur);
    operator++();
    return tmp;
}

List::Iterator& List::Iterator::operator--()
{
    if (!cur)
        throw std::out_of_range("Broken iterator.");
    if (!cur->prev)
        throw std::out_of_range(
                "Error during decrementation: iterator has run out of List.");
    cur = cur->prev;
    return *this;
}

List::Iterator List::Iterator::operator--(int)
{
    auto tmp(this->cur);
    operator--();
    return tmp;
}

bool List::Iterator::operator==(const List::Iterator& iter) const
{
    return cur == iter.cur;
}

bool List::Iterator::operator!=(const List::Iterator& iter) const
{
    return cur != iter.cur;
}

Dish& List::Iterator::operator*()
{
    return cur->data;
}

bool List::empty() const
{
    return this->length() == 0;
}

void List::erase(const List::Iterator pos)
{
    if (pos == NULL)
        return;
    if (!pos.cur->prev)
    {
        pos.cur->next->prev = NULL;
        head = pos.cur->next;
    }
    else if (!pos.cur->next)
    {
        pos.cur->prev->next = NULL;
        tail = pos.cur->prev;
    }
    else
    {
        List::Iterator prv(pos);
        --prv;
        List::Iterator nxt(pos);
        ++nxt;
        prv.cur->next = nxt.cur;
        nxt.cur->prev = prv.cur;
    }
    delete pos.cur;

}

void List::save(const std::string& path) const
{

    if (head == NULL){
        return;
    }

    std::ofstream file;
    file.open(path);

    if (!file.is_open())
        throw std::invalid_argument("Can't open the file.");
    auto it = List::Iterator(head);

    for (; it != tail; ++it)
        file << (*it).toString() << std::endl;
    file << (*it).toString() << std::endl;
    file.close();
}

void List::from(const std::string& path)
{
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        throw std::invalid_argument("Can't open the file.");
    std::string tmp;
    std::getline(file, tmp);
    this->insert(Dish(tmp));
    while (!file.eof())
    {
        std::getline(file, tmp);
        if (!tmp.empty())
            this->insert(Dish(tmp));
    }
    file.close();
}

void List::insert(const Dish& value)
{
    Node* new_obj = new Node;
    new_obj->data = std::move(value);
    if (head == NULL)
    {
        head = new_obj;
        tail = new_obj;
        return;
    }
    if (head == tail && !((head->data.energyValue()) < value.energyValue()))
    {
        head->next = new_obj;
        new_obj->prev = head;
        tail = new_obj;
        return;
    }
    if (head == tail && (head->data.energyValue()) < value.energyValue())
    {
        head->prev = new_obj;
        new_obj->next = head;
        head = new_obj;
        return;
    }
    auto iter = this->begin();

    while (iter != this->end() && !((*iter).energyValue() < value.energyValue()))
        ++iter;
    if (iter == this->begin())
    {
        new_obj->next = iter.cur;
        iter.cur->prev = new_obj;
        head = new_obj;
    }
    else if (iter == this->end())
    {
        new_obj->prev = iter.cur;
        iter.cur->next = new_obj;
        tail = new_obj;
    }
    else
    {
        new_obj->next = iter.cur;
        new_obj->prev = iter.cur->prev;
        new_obj->prev->next = new_obj;
        new_obj->next->prev = new_obj;
    }
}


bool List::operator==(List& other) const
{
    if (this->length() != other.length())
        return false;
    if (this->length() == 0)
        return true;
    auto it1 = this->begin();
    auto it2 = other.begin();
    while (it1 != this->end())
    {
        if (!((*it1).getName() == (*it2).getName() &&
              (*it1).getWeight() == (*it2).getWeight() &&
              (*it1).getContentAcids() == (*it2).getContentAcids() &&
              (*it1).getContentCarbons() == (*it2).getContentCarbons() &&
              (*it1).getContentFats() == (*it2).getContentFats() &&
              (*it1).getContentFibers() == (*it2).getContentFibers() &&
              (*it1).getContentProteins() == (*it2).getContentProteins()))
            return false;
        ++it1;
        ++it2;
    }
    return ((*it1).getName() == (*it2).getName() &&
            (*it1).getWeight() == (*it2).getWeight() &&
            (*it1).getContentAcids() == (*it2).getContentAcids() &&
            (*it1).getContentCarbons() == (*it2).getContentCarbons() &&
            (*it1).getContentFats() == (*it2).getContentFats() &&
            (*it1).getContentFibers() == (*it2).getContentFibers() &&
            (*it1).getContentProteins() == (*it2).getContentProteins());
}

bool List::operator!=(const List *other) const
{
    return !(this == other);
}

void List::pop(int pos){


        int count = this->length();

        if(pos < 1 || pos > count)
        {

            std::cout << "Incorrect position !!!\n";
            return;
        };

        int i = 1;

        Node * Del = head;

        while(i < pos)
        {

            Del = Del->next;
            i++;
        }


        Node * PrevDel = Del->prev;

        Node * AfterDel = Del->next;


        if(PrevDel != 0 && count != 1)
            PrevDel->next = AfterDel;

        if(AfterDel != 0 && count != 1)
            AfterDel->prev = PrevDel;

        if(pos == 1)
            head = AfterDel;
        if(pos == count)
            tail = PrevDel;

        delete Del;

        count--;
}

List::Node* List::search(double value) const {

    Node* tmp = head;

    while (value < tmp->data.energyValue()){
        tmp = tmp->next;
    }
    if (tmp == head){
        tmp->data.displayDish();
        //tmp->data.getName()
    }
    else{

        Node* tmp_prev = tmp->prev;

        if ((value - tmp->data.energyValue()) > (tmp_prev->data.energyValue() - value)){
            tmp_prev->data.displayDish();
            //tmp_prev->data.getName();
        }
        else {
            tmp->data.displayDish();
            //tmp->data.getName();
        }
    }


}
