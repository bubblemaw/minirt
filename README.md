## minirt
------------

# Bug
- Camera position and vector don't scale well because of scalar addition instead of matrix manipulation. Wont fix because of complexity.

# Current progress
All inmages below are in the same scene. The scene has:
- Outside sphere1:
  - 2 lights, 2 planes and 2 spheres:
  - ![image](https://github.com/user-attachments/assets/f56d29c0-ed7e-4295-af59-96f1d4588b25)

- Inside sphere1:
  - 2 lights, 2 planes intersections and 2 spheres: The sphere in the center is sphere2, there is a light inside sphere2.
  - ![image](https://github.com/user-attachments/assets/7857c835-21ff-429e-ab11-c609887bbaf4)

- Inside sphere2:
  - 1 lights: it is entirely blue because the light is blue, nothing else inside so everything is blue.
  - ![image](https://github.com/user-attachments/assets/b99cd29f-6335-4f8a-b309-c4ad340e4468)



