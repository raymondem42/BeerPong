# BeerPong
This is a Robot that will make a beer pong shot wherever the the cup is 

This is the rough outline of what we are going to do for the project. It should be done sometime in the next 10 days or so.

step 0.

We will need two camaras

the first camera will be placed by the camer

place a camer on the side of the launcher (so it can see the launher and the cup to shoot into)

measure where you place the cameras so that the angle of measurement is always consistent.

measure out to a point on the ground to get the x values.
(ex. measure something out to be 5 feet and then get the disance from the launcher
to the measure out thing)
(this will give you the relation of the x values and the x in feet)

do the same thing but with the y for the side camera.
now we have a basis (ie. 20 x values = 1 ft.)

measure the velocity of the shot (video record this thing going past a ruler or something

that will give time and distance so get the velo from that)


step 1. (get the horizontal angle for the stepper motor)

We do not need to use any converted measurements for this since we're just looking for the angle for the x value.

To get the angle we just use some trigonometry.

So we get the x and y value from camera one and use the following formula.

theta = arctan(x/y)

We use this angle to aim our launcher horizontally.


step 2 (theory). (get the vertical angle for another stepper motor) 

This arc will be found using camera 2 values and our converted values from earlier

first, let's go over the formula we need.

The projectile span we need is defined as deltaX = x1-x0 and deltaY = y1-y0

So the launcher will be x0 and the target x1. The same goes for y.

Now, we need to solve these next few equations to get the final formula (skip to end if you do not like algebra or just want to see the steps)

deltaX = v*t*cos(theta)

deltaY = v*t*sin(theta)1/2*G*t^2

Since tan(theta) = (deltaY+1/2*g*t^2)/(deltaX)
and 
we use it with the above formula since cos(tan^-1*z)=(1/sqrt(1+z^2))

simplified this comes out to 

deltaX = (v*t*deltaX)/(sqrt(deltaX^2+(y+1/2*g*t^2)^2)

When we rearrange to solve for t we get

t = (sqrt( 2v^2 - 2g*deltaY - 2*sqrt(v^4 - 2*g*v^2 - g^2*deltaX^2)

and finally when solving for theta we get

tan(theta) = (v^2)/(G*deltaX)- sqrt( (v^2 - (v^2 - 2*G*deltaY)/(G^2*deltaX)) - 1)

solve for theta (take the arctan of everything)

so it's 

theta = arctan( (v^2)/(G*deltaX)- sqrt( (v^2 - (v^2 - 2*G*deltaY)/(G^2*deltaX)) - 1) )
(end of theory)



step 2 actually. 

We use this formula to get the projectile for the two points

theta = arctan( (v^2)/(G*deltaX)- sqrt( (v^2 - (v^2 - 2*G*deltaY)/(G^2*deltaX)) - 1) )


We get the xy coordinates/measureents from camera 2 and plug it into this formula and solve for theta.
Make sure that we use the top of the bounding box for y (top of the cup)


v = velocity from when we measured it (lets say 100m/s for now)
deltaX= 500m
deltaY= 20m
G = 9.81 m/s
theta = ?

this will give us the angle of 

17.15 degrees

(must switch from radians to degrees)

(no solution means not possible) (meaning it's not in the range) 

keep in mind that one step is 1.8 degree so we just need to do some division to get the final variable

once everything is lined up, initiate the launcher 


step 3. 

show the code (this should be pretty simple tbh just arithmatic and then moving motors)

