template <typename... C> class System {
public:
  void on_update(C... components) {}
};
