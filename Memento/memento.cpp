#include <iostream>

class Memento
{
private:
    Memento() {}
    Memento(const size_t& state) : state_(state) {}
    ~Memento() {}
    auto SetState(const size_t& state) -> void { state_ = state; }
    auto GetState() -> size_t { return state_; }
    size_t state_;
    friend class Originator;
};

class Originator
{
public:
    Originator() : state_(3012) {}
    ~Originator() {}
    auto RestoreToMemento(Memento* nMemento) -> void { state_ = nMemento->GetState(); }
    auto CreateMemento() -> Memento* { return new Memento(state_); }
    auto ClearState() -> void { state_ = 0; }
    auto GetState() -> size_t { return state_; }
    auto add() -> void { ++state_; }
private:
    size_t state_;
};

class Caretaker
{
public:
    Caretaker() {}
    ~Caretaker() {}
    auto SetMemento(Memento* nMemento) -> void { mem_ = nMemento; }
    auto GetMemento() -> Memento*{ return this->mem_; }
private:
    Memento* mem_;
};

int main(){
    Originator A = *new Originator();
    Caretaker B = *new Caretaker();
    B.SetMemento(A.CreateMemento());
    A.ClearState();
    A.add()
    std::cout << A.GetState()<< "\n"; // 3013
    Case.RestoreToMemento(B.GetMemento());
    std::cout << A.GetState()<< "\n"; // 3012
}
