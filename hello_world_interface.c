#include<gtk/gtk.h>
typedef struct fenetre
{
  GtkWidget *window;
  GtkWidget* boutton;
  GtkApplication *app;
}window;

void destroying(GtkWidget *widget,gpointer *user_data)
{
  window *widget =(window  *)user_data;
  gtk_widget_destroys(GTK_WINDOW( widget.windwow));
}
void creating(GtkApplication *app ,gpointer* user_data)
{
  window *window_one=(window *)user_data;
  window_one.window=gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window_one.window),"HELLO WORLD");
  gtk_window_set_default_size(GTK_WINDOW(window_one.window),500,250);
  gtk_widget_set_border_width(GTK_CONTAINER(window_one.window),12);

  GtkWidget *vbox=gtk_box_new(GTK_ORIENTATION_VERTICALE,20);
  gtk_container_add(GTK_CONTAINER(window_one.window),vbox);
  window_one.boutton=gtk_button_new_with_label("cliquer pour sortir");
  gtk_widget_set_valign(widget_one.window,GTK_ALIGN_END);
  gtk_widget_set_halign(widget_one.window,GTK_ALIGN_END);
  gtk_box_pack_start(GTK_BOX(vbox),window_one.button,TRUE,TRUE,0);
   gtk_widget_show_all(window_one.window);
  g_signal_connect(window_one,"clicked",G_CALLBACK(destroying),window_one);
}
int main()
{
  window one_window;
  one_window.app=gtk_application_new("secure_data.app",G_APPLICATION_FLAGS_DEFAULT);
  
  g_application_run(app,argc,argv);
  g_signal_connect(app,"activate",G_CALLBACK(creating),&one_window);
  g_objet_unref(app);
}
