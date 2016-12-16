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
    auto CreateMemento() -> Memento* { return new Memento(state_); }
    auto SetMemento(Memento* Mem) -> Memento* { return Mem.SetState(state_); }
    auto ClearState() -> void { state_ = 0; }
    auto GetState() -> size_t { return state_; }
    auto add(size_t value_) -> void { state_ + = value_; }
    auto dubble() -> void { state_ = state_ * 2; }
    auto ReinstateMemento(Memento* Mem-> void { state_ = Mem->GetState(); }
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
    Originator A;
    Caretaker B;
    B.SetMemento(A.CreateMemento());
    A.ClearState();
    A.add(202);
    A.doubble();
    std::cout << A.GetState()<< "\n"; // 404
    Case.ReinstateMemento(B.GetMemento());
    std::cout << A.GetState()<< "\n"; // 3012
}
