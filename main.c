#include<gtk/gtk.h>
#include<stdio.h>
#include<string.h>


int on_button_continue_name_input_page_clicked();

GtkWidget *window_user_create;

GtkWidget *stack_user_create;

GtkWidget *box_name_input_user_create;
GtkWidget *text_entry_first_name;
GtkWidget *text_entry_second_name;
GtkWidget *button_continue_name_input_page;
GtkWidget *label_enter_your_name;


GtkWidget *box_D_O_B_input_user_create;
GtkWidget *box_D_O_B_input_user_create_row0;
GtkWidget *label_whats_your_D_O_B;
GtkWidget *calendar_input_D_O_B;
GtkWidget *button_continue_D_O_B_input_page;
GtkWidget *button_skip_D_O_B_input_page;


void on_text_entry_name_input_page_changed(GtkEntry *entry, gpointer user_data){

    const char *user_first_name = gtk_entry_get_text(GTK_ENTRY(text_entry_first_name));
    const char *user_second_name = gtk_entry_get_text(GTK_ENTRY(text_entry_second_name));

    gboolean valid = (strlen(user_first_name)> 2 && strlen(user_second_name)> 2 && strlen(user_first_name)< 10 && strlen(user_second_name)< 10);

    gtk_widget_set_sensitive(GTK_WIDGET(button_continue_name_input_page), valid);

}

int main(int argc, char *argv[]){
    gtk_init( &argc, &argv);

    
    window_user_create = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_user_create), 400, 300);

    stack_user_create = gtk_stack_new();
    gtk_container_add(GTK_CONTAINER(window_user_create), stack_user_create);

    box_name_input_user_create = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_stack_add_named(GTK_STACK(stack_user_create), box_name_input_user_create, "page_1");
    gtk_widget_set_margin_top(GTK_WIDGET(box_name_input_user_create), 50);  

    label_enter_your_name = gtk_label_new("What's ya Name?");
    gtk_container_add(GTK_CONTAINER(box_name_input_user_create), label_enter_your_name);
    gtk_widget_set_halign(GTK_WIDGET(box_name_input_user_create), GTK_ALIGN_CENTER);
    gtk_widget_set_margin_bottom(GTK_WIDGET(box_name_input_user_create), 20);


    text_entry_first_name = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(text_entry_first_name), "First Name...");
    gtk_container_add(GTK_CONTAINER(box_name_input_user_create), text_entry_first_name);
    gtk_widget_set_halign(GTK_WIDGET(box_name_input_user_create), GTK_ALIGN_CENTER);


    text_entry_second_name = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(text_entry_second_name), "Second Name...");
    gtk_container_add(GTK_CONTAINER(box_name_input_user_create), text_entry_second_name);
    gtk_widget_set_halign(GTK_WIDGET(box_name_input_user_create), GTK_ALIGN_CENTER);

    button_continue_name_input_page = gtk_button_new_with_mnemonic("Continue");
    gtk_widget_set_tooltip_text(GTK_WIDGET(button_continue_name_input_page), "Enter your name");
    gtk_container_add(GTK_CONTAINER(box_name_input_user_create), button_continue_name_input_page);
    gtk_widget_set_sensitive(button_continue_name_input_page, FALSE);

    box_D_O_B_input_user_create = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_stack_add_named(GTK_STACK(stack_user_create), box_D_O_B_input_user_create, "page_2");
    gtk_widget_set_margin_top(GTK_WIDGET(box_D_O_B_input_user_create), 50);

    label_whats_your_D_O_B = gtk_label_new("When were you born fam?");
    gtk_container_add(GTK_CONTAINER(box_D_O_B_input_user_create), label_whats_your_D_O_B);

    calendar_input_D_O_B = gtk_calendar_new();
    guint D_O_B_year, D_O_B_month, D_O_B_date;
    gtk_container_add(GTK_CONTAINER(box_D_O_B_input_user_create), calendar_input_D_O_B);
    gtk_widget_set_halign(GTK_WIDGET(calendar_input_D_O_B), GTK_ALIGN_CENTER);
    gtk_calendar_get_date(GTK_CALENDAR(calendar_input_D_O_B), &D_O_B_year, &D_O_B_month, &D_O_B_date);


    button_continue_D_O_B_input_page = gtk_button_new_with_mnemonic("Continue");
    gtk_widget_set_tooltip_text(GTK_WIDGET(button_continue_D_O_B_input_page), "Next Page");
    gtk_container_add(GTK_CONTAINER(box_D_O_B_input_user_create), button_continue_D_O_B_input_page);
    gtk_widget_set_halign(GTK_WIDGET(button_continue_D_O_B_input_page), GTK_ALIGN_CENTER);


    g_signal_connect(G_OBJECT(text_entry_first_name), "changed", G_CALLBACK(on_text_entry_name_input_page_changed), NULL);
    g_signal_connect(G_OBJECT(text_entry_second_name), "changed", G_CALLBACK(on_text_entry_name_input_page_changed), NULL);
    g_signal_connect(G_OBJECT(button_continue_name_input_page), "clicked", G_CALLBACK(on_button_continue_name_input_page_clicked), NULL);
    g_signal_connect(G_OBJECT(window_user_create), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    gtk_widget_show_all(GTK_WIDGET(window_user_create));
    gtk_main();
    return 0;

}

int on_button_continue_name_input_page_clicked(){
    gtk_stack_set_transition_type(GTK_STACK(stack_user_create), GTK_STACK_TRANSITION_TYPE_OVER_LEFT);
    gtk_stack_set_visible_child_name(GTK_STACK(stack_user_create), "page_2");

    return 0;
}