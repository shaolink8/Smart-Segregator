# Smart Segregator

### This was our submission for the hackathon Code2Create organized by ACM-VIT in 2020. Our standing was top 50.

We segregate waste based on its humidity, temperature and further make it accurate with the help of an image processing model. We also maintain a counter of number of waste dipatched and the space left in the container.

- The file "hack.ino" is a Node MCU code where we're calculating the distance with ultrasonic sensors and the temperature and humidity with DHT11 sensors.
The distance is used to evaluate the space left in the bin by placing the sensors on top of the bin.

- The file "pr.ino" is a Node MCU code where we're calculating the amount of waste dispatched into the bin by making use of lasers and photoresistors. Each time an item gets dropped into the bin, the laser is blocked and the respective threshold value is breached and we increase the counter by 1.

All the aforementioned values are being sent to the cloud Thingspeak via the WiFi module Node MCU. 
By making use of the Read APIs on Thingspeak, we can visualize these values better through a webapp or a user friendly GUI that gives the customer an idea about how much the bin is filled in terms of counters and meters and show percentages for wet, dry or food waste.

An image processing code was developed by a teammate that further classified the images of the waste as wet, dry or food waste.
