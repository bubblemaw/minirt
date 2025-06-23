## minirt
------------

# Bug
- Camera position and vector don't scale well because of scalar addition instead of matrix manipulation. Wont fix because of complexity.

# Current progress
All inmages below are in the same scene. The scene has:
- Outside sphere1:
  - 2 lights, 2 planes and 2 spheres:
  - ![image](https://github.com/user-attachments/assets/e96fa054-672a-44f2-bcc6-5db7e78ddfc2)

- Inside sphere1:
  - 2 lights, 2 planes intersections and 2 spheres: The sphere in the center is sphere2, there is a light inside sphere2.
  - ![image](https://github.com/user-attachments/assets/03d518b3-8c28-4ee4-bd5e-cff420022852)

- Inside sphere2:
  - 1 lights: it is entirely blue because the light is blue, nothing else inside so everything is blue.
  - ![image](https://github.com/user-attachments/assets/b99cd29f-6335-4f8a-b309-c4ad340e4468)



