

//header file includes in the code
#include<stdio.h>
#include<gtk/gtk.h>
#include<time.h>
#include<string.h>

GtkWidget *window_create_user;
GtkWidget *box_container_all;
GtkWidget *box_container_top_bar;
GtkWidget *box_container_rows0;
GtkWidget *box_container_rows1;
GtkWidget *box_container_rows2;
GtkWidget *box_container_rows3;
GtkWidget *box_container_rows4;
GtkWidget *box_container_columns;
GtkWidget *text_entry_first_name;
GtkWidget *text_entry_second_name;
GtkWidget *button_get_name;
GtkWidget *button_redirect_to_date_of_birth;
GtkWidget *button_back;
GtkWidget *header_bar;
GtkWidget *label_whats_your_name;

int main(int argc, char *argv[]);

//CSS Provider file data
void load_css(void){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    
    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);
    
    gtk_style_context_add_provider_for_screen(screen,
                                               GTK_STYLE_PROVIDER(provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    gtk_css_provider_load_from_file(provider,
                                    g_file_new_for_path("style.css"),
                                    NULL);
    
    g_object_unref(provider);
}

//on Text Entry Changed
void on_entry_changed(){
    const char *first_name = gtk_entry_get_text(GTK_ENTRY(text_entry_first_name));
    const char *second_name = gtk_entry_get_text(GTK_ENTRY(text_entry_second_name));

    gboolean enable = (strlen(first_name)> 2 && strlen(second_name)> 2 && strlen(first_name) < 10 && strlen(second_name) < 10);
    gtk_widget_set_sensitive(button_get_name, enable);

}


void on_continue_clicked(GtkWidget *widget, gpointer data){

    const char *first_name = gtk_entry_get_text(GTK_ENTRY(text_entry_first_name));
    const char *second_name = gtk_entry_get_text(GTK_ENTRY(text_entry_second_name));

    gtk_widget_hide(GTK_WIDGET(box_container_rows0));
    gtk_widget_hide(GTK_WIDGET(box_container_rows1));
    gtk_widget_hide(GTK_WIDGET(box_container_rows2));
    gtk_widget_hide(GTK_WIDGET(box_container_rows3));
    gtk_widget_hide(GTK_WIDGET(label_whats_your_name));


    GtkWidget *welcome_message = gtk_label_new(NULL);

    char message[200];

    sprintf(message, "Hi there,  %s %s\n\n\nLets Get Started !", first_name, second_name);
    gtk_label_set_text(GTK_LABEL(welcome_message), message);
    gtk_container_add(GTK_CONTAINER(box_container_rows4), welcome_message);
    gtk_widget_set_halign(GTK_WIDGET(welcome_message), GTK_ALIGN_CENTER);
    gtk_widget_set_margin_top(GTK_WIDGET(welcome_message), 75);
    gtk_label_set_justify(GTK_LABEL(welcome_message), GTK_JUSTIFY_CENTER);
    gtk_style_context_add_class(gtk_widget_get_style_context(welcome_message), "welcome_message");

    gtk_widget_show_all(GTK_WIDGET(welcome_message));
}

void on_back_clicked(void){
    gtk_widget_show(box_container_rows0);
    gtk_widget_show(GTK_WIDGET(box_container_rows1));
    gtk_widget_show(GTK_WIDGET(box_container_rows2));
    gtk_widget_show(GTK_WIDGET(box_container_rows3));
    gtk_widget_show(GTK_WIDGET(label_whats_your_name));
    gtk_widget_hide(box_container_rows4);
    gtk_entry_set_text(GTK_ENTRY(text_entry_first_name), "");
    gtk_entry_set_text(GTK_ENTRY(text_entry_second_name), "");
}

void on_second_name_activate(GtkEntry *entry, gpointer data) {
    if (gtk_widget_get_sensitive(button_get_name)) {
        on_continue_clicked(NULL, NULL);
    }
}

int main(int argc, char *argv[]){

    //Initialize the gtk library
    gtk_init(&argc, &argv);

    //load the css file properties
    load_css();

    header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "Academic Tracker App");

    //Window properties
    window_create_user = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_create_user), 400, 300);
    gtk_window_set_position(GTK_WINDOW(window_create_user), GTK_WIN_POS_CENTER);
    gtk_window_set_titlebar(GTK_WINDOW(window_create_user), header_bar);
    gtk_container_set_border_width(GTK_CONTAINER(window_create_user), 15);
 
    //CONTAINER TO CONTAIN ALL CONTAINERS WHICH WILL CONTAIN ELEMENTS
    box_container_all = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_container_add(GTK_CONTAINER(window_create_user), box_container_all);

    //Container for top bar
    box_container_top_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box_container_all), box_container_top_bar);

    //VERTICAL BOX CONTAINER
    box_container_columns = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_container_add(GTK_CONTAINER(box_container_all), box_container_columns);
    gtk_widget_set_margin_top(GTK_WIDGET(box_container_all), 50);

    //HORIZONTAL BOX CONTAINER1
    box_container_rows0 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box_container_columns), box_container_rows0);

    //HORIZONTAL BOX CONTAINER2
    box_container_rows1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box_container_columns), box_container_rows1);

    //HORIZONTAL BOX CONTAINER3
    box_container_rows2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box_container_columns), box_container_rows2);

    //HORIZONTAL BOX CONTAINER4
    box_container_rows3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box_container_columns), box_container_rows3);

    //HORIZONTAL BOX CONTAINER5
    box_container_rows4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box_container_columns), box_container_rows4);

    //TEXT ENTRY FOR FIRST NAME
    text_entry_first_name = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(text_entry_first_name), "Enter your First Name Here...");
    gtk_entry_set_max_length(GTK_ENTRY(text_entry_first_name), 50);
    gtk_container_add(GTK_CONTAINER(box_container_rows1), text_entry_first_name);
    gtk_widget_set_halign(GTK_WIDGET(box_container_rows1), GTK_ALIGN_CENTER);
    gtk_widget_set_tooltip_text(GTK_WIDGET(text_entry_first_name), "Enter Your First Name");

    //TEXT ENTRY FOR SECOND NAME
    text_entry_second_name = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(text_entry_second_name), "Enter your Second Name Here...");
    gtk_entry_set_max_length(GTK_ENTRY(text_entry_second_name), 50);
    gtk_container_add(GTK_CONTAINER(box_container_rows2), text_entry_second_name);
    gtk_widget_set_halign(GTK_WIDGET(box_container_rows2), GTK_ALIGN_CENTER);
    gtk_widget_set_tooltip_text(GTK_WIDGET(text_entry_second_name), "Enter Your Second Name");

    //PROPERTIES OF BUTTON TO GET FIRST NAME AND SECOND NAME
    button_get_name = gtk_button_new_with_mnemonic("_Continue");
    gtk_widget_set_size_request(button_get_name, 120, 40);
    gtk_widget_set_tooltip_text(button_get_name, "Enter Your Name");
    gtk_widget_set_halign(box_container_rows3, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(box_container_rows3), button_get_name);
    gtk_widget_set_sensitive(button_get_name, FALSE);

    label_whats_your_name = gtk_label_new("Whats your name?");
    gtk_container_add(GTK_CONTAINER(box_container_rows0), label_whats_your_name);
    gtk_widget_set_halign(GTK_WIDGET(box_container_rows0), GTK_ALIGN_CENTER);
    gtk_widget_set_margin_bottom(label_whats_your_name, 30);

    //PROPERTIES OF BUTTON FOR NAVIGATING BACK
    button_back = gtk_button_new_from_icon_name("go-previous", GTK_ICON_SIZE_BUTTON);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(header_bar), button_back);


    //the signals coming from the window elements
    g_signal_connect(button_back, "clicked", G_CALLBACK(on_back_clicked), NULL);
    g_signal_connect(text_entry_first_name, "changed", on_entry_changed, NULL);
    g_signal_connect(text_entry_second_name, "changed", on_entry_changed, NULL);
    g_signal_connect(text_entry_second_name, "activate", G_CALLBACK(on_second_name_activate), NULL);
    g_signal_connect(G_OBJECT(button_get_name), "clicked",G_CALLBACK(on_continue_clicked), NULL);
    g_signal_connect(G_OBJECT(window_create_user), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //show the window
    gtk_widget_show_all(GTK_WIDGET(window_create_user));
    gtk_main();

    return 0;
}