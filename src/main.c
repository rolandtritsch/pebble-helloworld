#include <pebble.h>

Window* g_main_window;
TextLayer* g_hello_text_layer;

void window_load(Window* w) {
  // We will add the creation of the Window's elements here soon!
  g_hello_text_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(g_hello_text_layer, GColorClear);
  text_layer_set_text_color(g_hello_text_layer, GColorBlack);
  text_layer_set_font(g_hello_text_layer, fonts_get_system_font("RESOURCE_ID_DROID_SERIF_28_BOLD"));
  text_layer_set_text(g_hello_text_layer, "!!!\nHello\nWorld\n!!!");

  layer_add_child(window_get_root_layer(w), (Layer*)g_hello_text_layer);
}

void window_unload(Window* w) {
  // We will safely destroy the Window's elements here!
  text_layer_destroy(g_hello_text_layer);
}

void init() {
  // Initialize the app elements here!
  g_main_window = window_create();
  window_set_window_handlers(g_main_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(g_main_window, true);
}

void deinit() {
  // De-initialize elements here to save memory!
  window_destroy(g_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
