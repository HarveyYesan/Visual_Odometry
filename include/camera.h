#ifndef CAMERA_H
#define CAMERA_H
#include "common.h"

namespace vo
{

// pinhole RGB-D camera model
class Camera
{
public:
    typedef std::shared_ptr<Camera> Ptr;
    Camera();
    Camera(float fx, float fy, float cx, float cy, float depth_scale=0);

    // coordinate transform: world, camera, pixel
    Eigen::Vector3d world2camera(const Eigen::Vector3d& p_w, const Sophus::SE3& T_c_w);
    Eigen::Vector3d camera2world(const Eigen::Vector3d& p_c, const Sophus::SE3& T_c_w);
    Eigen::Vector2d camera2pixel(const Eigen::Vector3d& p_c);
    Eigen::Vector3d pixel2camera(const Eigen::Vector2d& p_p, double depth=1.0);
    Eigen::Vector3d pixel2world(const Eigen::Vector2d& p_p, const Sophus::SE3& T_c_w, double depth=1.0);
    Eigen::Vector2d world2pixel(const Eigen::Vector3d& p_w, const Sophus::SE3& T_c_w);

private:
    // camera intrinsics
    float fx_;
    float fy_;
    float cx_;
    float cy_;
    float depth_scale_;
};

}

#endif // CAMERA_H

