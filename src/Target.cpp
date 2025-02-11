#include "Target.h"

Target::Target(Object& type, const glm::vec3& vec) : bufferType(type), mPosition(vec) {
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, vec);

    vec3 minCorner = vec3(-0.5f, -0.5f, -0.5f) + vec3(mPosition.x, mPosition.y, mPosition.z);
    vec3 maxCorner = vec3(0.5f, 0.5f, 0.5f) + vec3(mPosition.x, mPosition.y, mPosition.z);

    collisionBox = AABB(minCorner, maxCorner);
    isDestroyed = false;
}

std::vector<glm::vec3> Target::targetPositions = {
    glm::vec3(-3.0f, -3.0f, -10.0f),
    glm::vec3(0.0f, -3.0f, -10.0f),
    glm::vec3(3.0f, -3.0f, -10.0f),
    glm::vec3(-3.0f, 0.0f, -10.0f),
    glm::vec3(0.0f, 0.0f, -10.0f),
    glm::vec3(3.0f, 0.0f, -10.0f),
    glm::vec3(-3.0f, 3.0f, -10.0f),
    glm::vec3(0.0f, 3.0f, -10.0f),
    glm::vec3(3.0f, 3.0f, -10.0f)
};

void Target::Render() {
    bufferType.BindObject();
    bufferType.DrawObject(modelMatrix);
}

bool Target::OnMouseClick(const vec3& camOrigin, const vec3& camDirection) {
    return collisionBox.CheckCollision(camOrigin, camDirection);
}

Target* Target::clone() {

    int newPosition = HelperFunctions::GenerateRandomNumber(0, targetPositions.size());
    if (newPosition >= targetPositions.size()) {
        std::cout << "random function did not work as expected | value of newPosition: " << newPosition << std::endl;
        newPosition = 0;
    }
    Target* newTarget = new Target(bufferType, targetPositions[newPosition]);
    targetPositions.erase(targetPositions.begin() + newPosition);

    return newTarget;
}

void Target::destroy() {
    glm::vec3 targetPos = getTargetPosition();
    targetPositions.push_back(targetPos);
    isDestroyed = true;
}

glm::vec3 Target::getTargetPosition() {
    return mPosition;
}