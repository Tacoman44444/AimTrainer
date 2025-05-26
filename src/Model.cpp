#include "Model.h"

Model::Model(const char* filePath) {
    Load(filePath);
}

Model::Model(Primitives primitive, float radius) {
    Load(primitive, radius);
}

void Model::Load(const char* filePath) {
	// add .obj model loading logic
}

void Model::Load(Primitives primitive, float radius) {
    if (primitive == PRIMITIVE_SPHERE) {
        Mesh mesh = loadSphereMesh(radius, 36, 18);
        m_meshes.push_back(mesh);
    }
}

void Model::Draw(Shader& shader) {
	for (Mesh m : m_meshes) {
        shader.use();   
		m.Draw(shader);
	}
}

Mesh loadSphereMesh(float radius, int sectorCount, int stackCount) {

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;


    const float PI = 3.14159265359f;
    for (int i = 0; i <= stackCount; ++i) {
        float stackAngle = PI / 2 - i * PI / stackCount;
        float xy = radius * cosf(stackAngle);
        float y = radius * sinf(stackAngle);

        for (int j = 0; j <= sectorCount; ++j) {
            float sectorAngle = j * 2 * PI / sectorCount;
            float x = xy * cosf(sectorAngle);
            float z = xy * sinf(sectorAngle);

            // Position
            glm::vec3 position;
            position.x = x;
            position.y = y;
            position.z = z;

            // Normal = position normalized (since sphere is centered at origin)
            float lengthInv = 1.0f / radius;
            glm::vec3 normal;
            normal.x = x * lengthInv;
            normal.y = y * lengthInv;
            normal.z = z * lengthInv;

            // Texture Coordinates .... primitive models wont use these
            glm::vec2 texcoord;
            texcoord.x = 0;
            texcoord.y = 0;

            Vertex vertex = { position, normal, texcoord };

            vertices.push_back(vertex);
        }
    }

    // Indices
    for (int i = 0; i < stackCount; ++i) {
        unsigned int k1 = i * (sectorCount + 1);
        unsigned int k2 = k1 + sectorCount + 1;

        for (int j = 0; j < sectorCount; ++j, ++k1, ++k2) {
            if (i != 0) {
                indices.insert(indices.end(), { k1, k2, k1 + 1 });
            }
            if (i != (stackCount - 1)) {
                indices.insert(indices.end(), { k1 + 1, k2, k2 + 1 });
            }
        }
    }

    return Mesh(vertices, indices);
}