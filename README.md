# myGstreamer  
my gstreamer project  
* I've referred gstreamer tutorial source codes.
* (https://gstreamer.freedesktop.org/documentation/tutorials/basic/index.html?gi-language=c)  
# basic-tutorial-1  
* export GST_DEBUG=3  
* Error :souphttpsrc gstsouphttpsrc.c:1380:gst_soup_http_src_parse_status:<source> error: Unacceptable TLS certificate (6),  
** $ sudo apt install --reinstall ca-certificates  
** because the public key is not available: NO_PUBKEY 4EB27DB2A3B88B8B  
** $ sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 4EB27DB2A3B88B8B  
** $ sudo fuser -v /var/cache/debconf/config.dat  
*** root       6043 F.... frontend  
*** $ sudo kill 6043  
** $ sudo dpkg --configure -a  
** resolved  
