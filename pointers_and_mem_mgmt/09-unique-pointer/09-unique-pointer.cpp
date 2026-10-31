#include <print>
#include <memory>  // Provides 'std::make_unique' and 'std::unique_ptr'
#include <cstddef>


class Resource {
public:
    std::size_t number;

    Resource(std::size_t number) : number(number) {
        std::println("Allocating resource...");
    }

    ~Resource(){
        std::println("Destructing resource...");
    }

private:
};

int main () {
    Resource resource_1 = std::make_unique<Resource>(number);

    return 0;
}
