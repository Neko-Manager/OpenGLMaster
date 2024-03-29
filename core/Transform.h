#pragma once

///Includes from glm-library
#define GLM_ENABLE_EXPERIMENTAL 

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

///Public class
struct Transform
{
	///Constructor for object instance
	Transform() : mPosition(glm::vec3(0.0f)), mRotation(glm::quat(glm::identity<glm::quat>())), mScale(glm::vec3(1.0f)){}

	///Adders
	void AddRotation(const glm::quat& rot)
	{
		mRotation = mRotation * rot; //Setting the rotation of the object to rot
		mRotation = glm::normalize(mRotation); //Normalizing the quaternions (Quaternions = 4D extension of complex numbers)
	}

    void AddYaw(float angleDegrees)
    {
        float angleRadians = glm::radians(angleDegrees);
        glm::quat yawRotation = glm::angleAxis(angleRadians, glm::vec3(0.0f, 1.0f, 0.0f));
        AddRotation(yawRotation);
    }

    void AddPitch(float angleDegrees)
    {
        float angleRadians = glm::radians(angleDegrees);
        glm::vec3 rightVector = glm::rotate(mRotation, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::quat pitchRotation = glm::angleAxis(angleRadians, rightVector);
        AddRotation(pitchRotation);
    }

    /// Setters
    void SetPosition(const glm::vec3& pos) { mPosition = pos; }
    void SetRotation(const glm::quat& rot) { mRotation = rot; }
    void SetScale(const glm::vec3& scl) { mScale = scl; }

    void SetRotation(const glm::vec3& forwardDirection, const glm::vec3& upDirection = glm::vec3(0.0f, 1.0f, 0.0f))
    {
        glm::vec3 normalizedForward = glm::normalize(forwardDirection);
        glm::vec3 defaultForward(0.0f, 0.0f, -1.0f);
        glm::quat newRotation = glm::rotation(defaultForward, normalizedForward);
        mRotation = newRotation;
    }

    void SetRotationFromPitch(float pitchDegrees)
    {
        float pitchRadians = glm::radians(pitchDegrees);
        glm::quat pitchRotation = glm::angleAxis(pitchRadians, glm::vec3(1.0f, 0.0f, 0.0f));
        mRotation = pitchRotation;
    }

    void SetRotationFromYaw(float yawDegrees)
    {
        float yawRadians = glm::radians(yawDegrees);
        glm::quat yawRotation = glm::angleAxis(yawRadians, glm::vec3(0.0f, 1.0f, 0.0f));
        mRotation = yawRotation;
    }

    void SetTransformMatrix(const glm::mat4& matrix)
    {
        glm::vec3 scale;
        glm::quat rotation;
        glm::vec3 translation;
        glm::vec3 skew;
        glm::vec4 perspective;

        glm::decompose(matrix, scale, rotation, translation, skew, perspective);

        SetPosition(translation);
        SetRotation(rotation);
        SetScale(scale);
    }

    /// Getters
    const glm::vec3& GetPosition() const { return mPosition; }
    const glm::quat& GetRotation() const { return mRotation; }
    const glm::vec3& GetScale() const { return mScale; }

    float GetCurrentPitch() const
    {
        glm::vec3 eulerAngles = glm::eulerAngles(mRotation);
        float pitch = eulerAngles.x;
        return glm::degrees(pitch);
    }

    float GetCurrentYaw() const
    {
        glm::vec3 eulerAngles = glm::eulerAngles(mRotation);
        float yaw = eulerAngles.y;
        return glm::degrees(yaw);
    }

    glm::mat4 GetTransformMatrix() const
    {
        glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), mScale);
        glm::mat4 rotMat = glm::toMat4(mRotation);
        glm::mat4 translateMat = glm::translate(glm::mat4(1.0f), mPosition);
        return translateMat * rotMat * scaleMat;
    }

    glm::vec3 GetRight() const
    {
        return glm::rotate(mRotation, glm::vec3(1.0f, 0.0f, 0.0f));
    }

    glm::vec3 GetForward() const
    {
        return glm::rotate(mRotation, glm::vec3(0.0f, 0.0f, -1.0f));
    }

    glm::vec3 GetUp() const
    {
        return glm::rotate(mRotation, glm::vec3(0.0f, 1.0f, 0.0f));
    }

private:
	glm::vec3 mPosition{};
	glm::quat mRotation{};
	glm::vec3 mScale{};
};