/*
As explained in our post on how web caching works, a cache, whether 
deployed on one local server or through a Content Delivery Network, 
stores a copy of the files that make up a webpage so they can be 
delivered to visitors more quickly. By caching copies of image files, 
CSS, and HTML documents, the origin server does not have to generate 
these files each time a new visitor comes to the website. This both 
improves page load time and decreases stress on the origin server, 
meaning a website can serve more visitors at once.

Because modern websites are constantly being updated - whether it¡¯s 
a media site updating the articles on their homepage or an ecommerce 
site updating inventory of a certain product - files are set to expire 
after a set period of time, which may be a minute or an hour. Each 
time a file in the cache expires, it needs to be re-collected from 
the origin server.

The first visitor to visit a website after a cache is initially set up 
or a cache expires will go through an empty or cold cache and 
experience a ¡°cache miss.¡± The cache will visit the origin server 
to retrieve the file, deliver it to the visitor and keep the file in 
the cache so it is then a full or warm cache. Each subsequent user 
that visits before the cache expires again will be served from 
cache - a ¡°cache hit¡± for all files that have been stored.

To summarize, a cold cache is one that does not have any files stored 
in it, and a warm cache has files stored already and is prepared to 
serve visitors.
*/
