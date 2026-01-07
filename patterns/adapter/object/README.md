Лайфхак

```cpp
// Где-то в коде:
Duck my_duck;

// Ты создаёшь адаптер, который использует ИМЕННО ЭТОТ объект:
class DuckObjectAdapter : public IBird {
    Duck& duck; // ← ссылка на существующий объект!
public:
    DuckObjectAdapter(Duck& d) : duck(d) {}
    void Sound() override {
        duck.quaq();
    }
};

// Использование:
DuckObjectAdapter adapter(my_duck);
adapter.Sound(); // ← работает с my_duck
```