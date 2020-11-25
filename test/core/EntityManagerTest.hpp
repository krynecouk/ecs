#include "../../lib/catch2/catch.hpp"
#include "../../src/core/EntityManager.hpp"

SCENARIO("archetype is generated from given components", "[archetype]") {
  GIVEN("entity manager") {
    EntityManager em{};

    WHEN("no component is given") {
      THEN("0b0 is returned") {}
    }

    WHEN("one component is given") {
      THEN("0b1 is returned") {}
    }

    WHEN("one component is given again") {
      THEN("0b1 is returned") {}
    }

    WHEN("two components are given") {
      THEN("0b11 is returned") {}
    }
  }
}

TEST_CASE("entity manager", "[EntityManager]") {
  EntityManager em{};

  SECTION("should generate archetype from given component types") {
    REQUIRE(em.create_archetype({typeid(EntityManager), typeid(Foo)}) ==
            0b0001);
  }
}
