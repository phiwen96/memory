#pragma once
#include <iostream>
//#include <ranges>
#include <concepts>
#include <memory>
#include <new>

using namespace std;

struct foo {
	constexpr foo(int* i) : ptr{i} {}

	constexpr ~foo() {
		delete ptr;
	}

	int* ptr;
};

struct bar {
	// foo f{new int};
    
    constexpr bar () : f (new int)
    {
        // new (f.ptr) int (3);
        construct_at(f.ptr, 4);
    }
    foo f;
};

constexpr auto test3() {
    // constexpr foo f(new int);
	bar b;
    // ::new (b.f.ptr) int (3);
	return true;
}

static_assert(test3());
// constexpr int
// baz2 ()
// {
//   std::allocator<int> alloc;
//   using A = std::allocator_traits<std::allocator<int>>;
//   auto a = A::allocate(alloc, 1);            // obtain storage for an int
//   A::construct(a);                           // calls std::construct_at
//   *a = 1;
//   *a = *a + 2;
//   int r = *a;
//   A::destroy(alloc, a);                      // calls std::destroy_at
//   A::deallocate(alloc, a, 1);                // release storage
//   return r;
// }



// constexpr auto q = baz2 ();
consteval int* aa ()
{
    return new int;
}
// int main (){
//     constexpr auto aaa = test3();
//     cout << "hi" << endl;
//     cout << 3 << endl;

//     // constexpr foo f (new int);
//     // constexpr auto a = aa();
//     //  auto a = std::allocator<int>::allocate(1); // obtain storage for an int

// //     constexpr auto a = new int;
// //   std::construct_at(a);                      // begin lifetime of an int
// //   *a = 1;
// //   *a = *a + 2;
// //   int r = *a;
// //   std::destroy_at(a);                        // end lifetime
// //   std::allocator<int>::deallocate(a, 1);     // release storage
//     return 0;
// }
