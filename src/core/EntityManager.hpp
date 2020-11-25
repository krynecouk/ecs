#include "Archetype.hpp"
#include "ComponentType.hpp"
#include "Entity.hpp"
#include "iostream"
#include "map"
#include "queue"
#include "typeindex"
#include "unordered_map"
#include <initializer_list>
#include <ostream>

class EntityManager {
private:
  const int MAX_ENTITIES{100'000}; // TODO
  std::queue<Entity> available_entities{};
  ComponentType last_component_type{"0001"};
  std::map<std::type_index, ComponentType>
      component_types{}; // TODO; unordered?

public:
  EntityManager() {
    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
      available_entities.push(entity);
    }
  };

  void destroy_entity(Entity entity) { available_entities.push(entity); }

  Entity create_entity() {
    const Entity id = available_entities.front();
    available_entities.pop();
    return id;
  };

  Archetype
  create_archetype(const std::initializer_list<std::type_index> components) {
    Archetype archetype{0};
    for (auto &component : components) {
      std::cout << "component: " << component.name() << "\n";
      auto it = component_types.find(component);
      if (it == component_types.end()) {
        component_types[component] = 0b00001;
        last_component_type <<= 1;
      }
      archetype |= it->second;
    }
    return archetype;
  };
};
