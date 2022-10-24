#include <gst/gst.h>

int
main (int argc, char *argv[])
{
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Build the pipeline */
  pipeline =
      gst_parse_launch
      ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);

  //gst_parse_launch:
  //  source -> sink (multimedia flows)
  //  pipeline : assemble elements manually
  //  shortcut
  //playbin
  //  single element
  //  source, sink (whole pipeline)  

  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);
  // state : PLAYING -> playback will start

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline); // retrieves the pipeline's bus
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, // block until error or EOS
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* See next tutorial for proper error message handling/parsing */
  if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
    g_error ("An error occurred! Re-run with the GST_DEBUG=*:WARN environment "
        "variable set for more details.");
  }

  /* Free resources */
  gst_message_unref (msg); // msg from gst_bus_timed_filtered
  gst_object_unref (bus); // bus from gst_element_get_bus
  gst_element_set_state (pipeline, GST_STATE_NULL); // pipeline : NULL state
  gst_object_unref (pipeline); // destroy pipeline
  return 0;
}
