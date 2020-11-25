#include <array>
template <typename... T> class Archetype2 {

private:
  std::array<std::tuple<T...>, 1000> archetype_components;
};
