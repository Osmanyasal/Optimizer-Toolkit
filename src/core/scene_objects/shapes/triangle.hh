#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__SCENE_OBJECTS__TRIANGLE_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__SCENE_OBJECTS__TRIANGLE_HH

#include <inttypes.h>
#include <vector>
#include <glm_utils.hh>

namespace OPTKIT::core::scene
{
    class Triangle2D
    {
    public:
        static std::vector<float> get_positions(const glm::vec3 &size);
        std::vector<float> get_positions(uint32_t subtext_size, uint32_t x, uint32_t y);
        static std::vector<float> get_colors(const glm::vec4 &color = glm::vec4{1.0f});
        static std::vector<float> get_normals();
        static std::vector<float> get_texture_coordinates(float tile_factor = 1.0f);
        static std::vector<uint32_t> get_index_buffer();

    private:
        Triangle2D(/* args */);
        ~Triangle2D();
    };
} // namespace OPTKIT::core::scene

#endif