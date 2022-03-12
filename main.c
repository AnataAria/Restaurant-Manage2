#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <stdlib.h>

typedef struct{
    char ID[128];
    char userName[128];
    char tableNumber[5];
    char salmonQuantity[128];
    char friedRiceQuantity[128];
    char spaghettiQuantity[128];
    char musselQuantity[128];
    char phoBoQuantity[128];
    char pumpkinSoupQuantity[128];
    char saladQuantity[128];
    char applePieQuantity[128];
    char eggBenedictQuantity[128];
    char springRollQuantity[128];
    char grilledPorkQuantity[128];
    char beefSteakQuantity[128];
    char summarize[128];
} CustomerOrderInfo;

typedef struct {
    char dishName[256];
    char dishPrice[256];
    int quantity;
} dishes;

typedef struct {
    char ID[256];
    char guestName[256];
    char table[5];
    //101, 102, 103, 104, 105.
} guestData;

typedef struct {
    char userName[256];
    char passWord[256];
}userPass;

dishes dish[13];
CustomerOrderInfo customers[100];
guestData guest;
userPass adminLogin[256];

char usernameEntry[256];
char passwordEntry[256];
char quantityChar[256];
int row = 0;
int column = 0; 
int MAX = 1000;

//-------------------------Declare elements--------------------------

GtkWidget *loginWindow;
GtkWidget *fixed1;
GtkWidget *welcome1;
GtkWidget *background1;
GtkWidget *question;
GtkWidget *guestButton;
GtkWidget *managerButton;
GtkBuilder *loginBuilder;

GtkWidget *managerLogin;
GtkWidget *fixed2;
GtkWidget *background2;
GtkWidget *managerLoginText;
GtkWidget *username;
GtkWidget *password;
GtkWidget *signInButton;
GtkWidget *welcome2;
GtkWidget *managerBackButton;
GtkWidget *label;
GtkBuilder *managerBuilder;

GtkWidget *guestWindow;
GtkWidget *fixed3;
GtkWidget *welcome3;
GtkWidget *background3;
GtkWidget *guestText;
GtkWidget *guestName;
GtkWidget *confirmButton;
GtkWidget *table;
GtkWidget *guestBackButton;
GtkBuilder *guestBuilder;

GtkWidget *dashboard;
GtkWidget *fixed4;
GtkWidget *sidebar;
GtkWidget *totalRevenueBox;
GtkWidget *totalDishBox;
GtkWidget *totalCustomerBox;
GtkWidget *orderReportBox;
GtkWidget *mostOrderBox;
GtkWidget *testButton;
GtkBuilder *dashboardBuilder;

GtkWidget *orderWindow;
GtkWidget *fixed;
GtkWidget *sidebar;
GtkWidget *ordersGrid;
GtkWidget *guestNameOrder;
GtkWidget *box1;
GtkWidget *confirmOrderButton;
GtkWidget *totalLabel;
GtkWidget *stack1;
GtkWidget *switcher;
GtkWidget *menuGrid1;
GtkWidget *orderButton1;
GtkWidget *dishImage1;
GtkWidget *dishName1;
GtkWidget *dishPrice1;
GtkWidget *orderButton2;
GtkWidget *dishImage2;
GtkWidget *dishName2;
GtkWidget *dishPrice2;
GtkWidget *orderButton3;
GtkWidget *dishImage3;
GtkWidget *dishName3;
GtkWidget *dishPrice3;
GtkWidget *orderButton4;
GtkWidget *dishImage4;
GtkWidget *dishName4;
GtkWidget *dishPrice4;
GtkWidget *orderButton5;
GtkWidget *dishImage5;
GtkWidget *dishName5;
GtkWidget *dishPrice5;
GtkWidget *orderButton6;
GtkWidget *dishImage6;
GtkWidget *dishName6;
GtkWidget *dishPrice6;
GtkWidget *menuGrid2;
GtkWidget *orderButton7;
GtkWidget *dishImage7;
GtkWidget *dishName7;
GtkWidget *dishPrice7;
GtkWidget *orderButton8;
GtkWidget *dishImage8;
GtkWidget *dishName8;
GtkWidget *dishPrice8;
GtkWidget *orderButton9;
GtkWidget *dishImage9;
GtkWidget *dishName9;
GtkWidget *dishPrice9;
GtkWidget *orderButton10;
GtkWidget *dishImage10;
GtkWidget *dishName10;
GtkWidget *dishPrice10;
GtkWidget *orderButton11;
GtkWidget *dishImage11;
GtkWidget *dishName11;
GtkWidget *dishPrice11;
GtkWidget *orderButton12;
GtkWidget *dishImage12;
GtkWidget *dishName12;
GtkWidget *dishPrice12;
GtkWidget *label1_dishName;
GtkWidget *label1_dishPrice;
GtkWidget *label1_quantity;
GtkWidget *image1;
GtkWidget *label2_dishName;
GtkWidget *label2_dishPrice;
GtkWidget *label2_quantity;
GtkWidget *image2;
GtkWidget *label3_dishName;
GtkWidget *label3_dishPrice;
GtkWidget *label3_quantity;
GtkWidget *image3;
GtkWidget *label4_dishName;
GtkWidget *label4_dishPrice;
GtkWidget *label4_quantity;
GtkWidget *image4;
GtkWidget *label5_dishName;
GtkWidget *label5_dishPrice;
GtkWidget *label5_quantity;
GtkWidget *image5;
GtkWidget *label6_dishName;
GtkWidget *label6_dishPrice;
GtkWidget *label6_quantity;
GtkWidget *image6;
GtkWidget *label7_dishName;
GtkWidget *label7_dishPrice;
GtkWidget *label7_quantity;
GtkWidget *image7;
GtkWidget *label8_dishName;
GtkWidget *label8_dishPrice;
GtkWidget *label8_quantity;
GtkWidget *image8;
GtkWidget *label9_dishName;
GtkWidget *label9_dishPrice;
GtkWidget *label9_quantity;
GtkWidget *image9;
GtkWidget *label10_dishName;
GtkWidget *label10_dishPrice;
GtkWidget *label10_quantity;
GtkWidget *image10;
GtkWidget *label11_dishName;
GtkWidget *label11_dishPrice;
GtkWidget *label11_quantity;
GtkWidget *image11;
GtkWidget *label12_dishName;
GtkWidget *label12_dishPrice;
GtkWidget *label12_quantity;
GtkWidget *image12;
GtkWidget *scroll1;
GtkWidget *view1;
GtkWidget *orderBackButton;
GtkWidget *removeButton;
GtkWidget *orderNumber;
GtkBuilder *orderWindowBuilder;

G_MODULE_EXPORT void on_managerButton_clicked(GtkButton *b);
G_MODULE_EXPORT void on_guestButton_clicked(GtkButton *b);
G_MODULE_EXPORT void on_managerBackButton_clicked(GtkButton *b);
G_MODULE_EXPORT void on_guestBackButton_clicked(GtkButton *b);
G_MODULE_EXPORT void on_guestName_changed(GtkEntry *e);
G_MODULE_EXPORT void on_confirmButton_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderBackButton_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton1_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton2_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton3_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton4_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton5_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton6_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton7_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton8_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton9_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton10_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton11_clicked(GtkButton *b);
G_MODULE_EXPORT void on_orderButton12_clicked(GtkButton *b);
G_MODULE_EXPORT void on_removeButton_clicked(GtkButton *b);

int idGenerator();
int readHistoryID();
void backupDataBase(CustomerOrderInfo a[]);
void uploadToFile(CustomerOrderInfo a[]);
void uploadCustomerOrderData(CustomerOrderInfo a[]);
void moveData(guestData a, dishes b[],CustomerOrderInfo c[], int sum);
int calculateSummary(dishes a[],CustomerOrderInfo b[],guestData c);
int totalRevenue(CustomerOrderInfo a[]);
int totalDishOrdered(CustomerOrderInfo a[]);
int totalCustomer();
void uploadUserPass(userPass a[]);
int checkNamePass(userPass a[],char userName[], char password[]);
    
//---------------------------------GUI-----------------------------------------------

void loginUI() 
{
    loginBuilder = gtk_builder_new_from_file("Login.glade");
    loginWindow = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "loginWindow"));
    g_signal_connect(loginWindow, "destroy",G_CALLBACK(gtk_main_quit) ,NULL);
    gtk_builder_connect_signals(loginBuilder, NULL);
    fixed1 = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "fixed1"));
    background1 = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "background1" ));
    welcome1 = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "welcome1"));
    question = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "question"));
    guestButton = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "guestButton"));
    managerButton = GTK_WIDGET(gtk_builder_get_object(loginBuilder, "managerButton"));
    gtk_widget_show(loginWindow);
}

void managerLoginUI()
{
    managerBuilder = gtk_builder_new_from_file("ManagerLogin.glade");
    managerLogin = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "managerLogin"));
    g_signal_connect(managerLogin,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(managerBuilder, NULL);
    fixed2 = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "fixed2"));
    background2 = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "background2"));
    welcome2 = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "welcome2"));
    managerLoginText = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "managerLoginText"));
    username = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "username"));
    password = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "password"));
    signInButton = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "signInButton"));
    managerBackButton = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "managerBackButton"));
    label = GTK_WIDGET(gtk_builder_get_object(managerBuilder, "label"));
}

void guestWindowUI()
{
    guestBuilder = gtk_builder_new_from_file("GuestWindow.glade");
    guestWindow = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "guestWindow"));
    g_signal_connect(guestWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(guestBuilder, NULL);
    fixed3 = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "fixed3"));
    background3 = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "background3"));
    welcome3 = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "welcome3"));
    guestText = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "guestText"));
    guestName = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "guestName"));
    table = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "table"));
    confirmButton = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "confirmButton"));
    guestBackButton = GTK_WIDGET(gtk_builder_get_object(guestBuilder, "guestBackButton"));
    gtk_widget_show(guestWindow);
}

void dashboardUI()
{
    dashboardBuilder = gtk_builder_new_from_file("Dashboard.glade");
    dashboard = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"dashboard"));
    g_signal_connect(dashboard, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(dashboardBuilder, NULL);
    fixed4 = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"fixed4"));
    totalRevenueBox = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"totalRevenueBox"));
    totalDishBox = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"totalDishBox"));
    totalCustomerBox = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"totalCustomerBox"));
    orderReportBox = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"orderReportBox"));
    mostOrderBox = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"mostOrderBox"));
    testButton = GTK_WIDGET(gtk_builder_get_object(dashboardBuilder,"testButton"));
}

void orderWindowUI()
{    
    orderWindowBuilder = gtk_builder_new_from_file("OrderWindow.glade");
    orderWindow = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderWindow"));
    g_signal_connect(orderWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(orderWindowBuilder, NULL);
    fixed = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "fixed"));
    sidebar = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "sidebar"));
    ordersGrid = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "ordersGrid"));
    guestNameOrder = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "guestNameOrder"));
    box1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "box1"));
    confirmOrderButton = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "confirmOrderButton"));
    totalLabel = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "totalLabel"));
    stack1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "stack1"));
    menuGrid1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "menuGrid1"));
    orderButton1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton1"));
    dishImage1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage1"));
    dishName1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName1"));
    dishPrice1 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice1"));
    orderButton2 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton2"));
    dishImage2 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage2"));
    dishName2 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName2"));
    dishPrice2 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice2"));
    orderButton3 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton3"));
    dishImage3 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage3"));
    dishName3 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName3"));
    dishPrice3 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice3"));
    orderButton4 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton4"));
    dishImage4 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage4")); 
    dishName4 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName4"));
    dishPrice4 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice4"));
    orderButton5 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton5")); 
    dishImage5 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage5")); 
    dishName5 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName5"));
    dishPrice5 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice5")); 
    orderButton6 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton6")); 
    dishImage6 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage6")); 
    dishName6 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName6"));
    dishPrice6 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice6"));
    menuGrid2 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "menuGrid2"));
    orderButton7 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton7")); 
    dishImage7 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage7")); 
    dishName7 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName7"));
    dishPrice7 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice7"));
    orderButton8 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton8"));
    dishImage8 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage8"));
    dishName8 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName8"));
    dishPrice8 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice8"));
    orderButton9 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton9"));
    dishImage9 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage9"));
    dishName9 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName9"));
    dishPrice9 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice9"));
    orderButton10 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton10"));
    dishImage10 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage10"));
    dishName10 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName10"));
    dishPrice10 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice10"));
    orderButton11 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton11"));
    dishImage11 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage11"));
    dishName11 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName11"));
    dishPrice11 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice11"));
    orderButton12 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderButton12"));
    dishImage12 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishImage12"));
    dishName12 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishName12"));
    dishPrice12 = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "dishPrice12"));   
    orderBackButton = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder, "orderBackButton"));
    removeButton = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder,"removeButton"));
    orderNumber = GTK_WIDGET(gtk_builder_get_object(orderWindowBuilder,"orderNumber"));

    strcpy(dish[1].dishName, gtk_label_get_text(GTK_LABEL(dishName1)));
    strcpy(dish[2].dishName, gtk_label_get_text(GTK_LABEL(dishName2)));
    strcpy(dish[3].dishName, gtk_label_get_text(GTK_LABEL(dishName3)));
    strcpy(dish[4].dishName, gtk_label_get_text(GTK_LABEL(dishName4)));
    strcpy(dish[5].dishName, gtk_label_get_text(GTK_LABEL(dishName5)));
    strcpy(dish[6].dishName, gtk_label_get_text(GTK_LABEL(dishName6)));
    strcpy(dish[7].dishName, gtk_label_get_text(GTK_LABEL(dishName7)));
    strcpy(dish[8].dishName, gtk_label_get_text(GTK_LABEL(dishName8)));
    strcpy(dish[9].dishName, gtk_label_get_text(GTK_LABEL(dishName9)));
    strcpy(dish[10].dishName, gtk_label_get_text(GTK_LABEL(dishName10)));
    strcpy(dish[11].dishName, gtk_label_get_text(GTK_LABEL(dishName11)));
    strcpy(dish[12].dishName, gtk_label_get_text(GTK_LABEL(dishName12)));

    strcpy(dish[1].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice1)));
    strcpy(dish[2].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice2)));
    strcpy(dish[3].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice3)));
    strcpy(dish[4].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice4)));
    strcpy(dish[5].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice5)));
    strcpy(dish[6].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice6)));
    strcpy(dish[7].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice7)));
    strcpy(dish[8].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice8)));
    strcpy(dish[9].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice9)));
    strcpy(dish[10].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice10)));
    strcpy(dish[11].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice11)));
    strcpy(dish[12].dishPrice, gtk_label_get_text(GTK_LABEL(dishPrice12)));

    gtk_label_set_text(GTK_LABEL(dishPrice1), "60.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice2), "45.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice3), "45.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice4), "50.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice5), "50.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice6), "50.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice7), "35.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice8), "40.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice9), "50.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice10), "35.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice11), "60.000đ");
    gtk_label_set_text(GTK_LABEL(dishPrice12), "70.000đ");

    
    for (int i = 1; i < 13; i++)
    dish[i].quantity = 0;
}

//Function

// int Login(char *username, char *password)
// {
//     if(strcmp(username, "Vinh") == 0 && strcmp(password, "96200312345") == 0) {
//         return 1;
//     }
//     else {
//         return 0;
//     }
// }

void on_managerButton_clicked(GtkButton *b) {
    gtk_widget_show(managerLogin);
    gtk_widget_hide(loginWindow);
    gtk_widget_hide(guestWindow);
}

void on_guestButton_clicked(GtkButton *b) {
    gtk_widget_show(guestWindow);
    gtk_widget_hide(loginWindow);
    gtk_widget_hide(managerLogin);
}

void on_guestBackButton_clicked(GtkButton *b) {
    gtk_widget_show(loginWindow);
    gtk_widget_hide(guestWindow);
    gtk_widget_hide(managerLogin);
}

void on_managerBackButton_clicked(GtkButton *b) {
    gtk_widget_show(loginWindow);
    gtk_widget_hide(guestWindow);
    gtk_widget_hide(managerLogin);
}

void on_confirmOrderButton_clicked(GtkButton *b)
{   
    g_print("\n%d", calculateSummary(dish,customers,guest));
}

void on_orderBackButton_clicked(GtkButton *b)
{
    gtk_widget_show(guestWindow);
    gtk_widget_hide(orderWindow);
}

void cssInsertion()
{
    GdkDisplay *display;
    GdkScreen *screen;
    GtkCssProvider  *provider;
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    GError *error = NULL;
    provider  = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "login.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void on_guestName_changed(GtkEntry *e)
{
    sprintf(guest.guestName, "%s", gtk_entry_get_text(e));
}

void on_table_changed(GtkEntry *e)
{
    sprintf(guest.table, "%s", gtk_entry_get_text(e));
}

void on_username_changed(GtkEntry *e)
{
   sprintf(usernameEntry, "%s", gtk_entry_get_text(e)); 
}

void on_password_changed(GtkEntry *e)
{
   sprintf(passwordEntry, "%s", gtk_entry_get_text(e)); 
}

void on_signInButton_clicked(GtkButton *b)
{
    if (checkNamePass(adminLogin,usernameEntry, passwordEntry) == 0)
    {
        gtk_label_set_text(GTK_LABEL(label), gtk_label_get_text(GTK_LABEL(welcome1)));
        // gtk_widget_hide(managerLogin);
        // gtk_widget_show(guestWindow);
    }
    else gtk_label_set_text(GTK_LABEL(label), "Login failed");
}

void on_orderButton1_clicked(GtkButton *b)
{
    if (dish[1].quantity == 0)
    {
        dish[1].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label1_dishName = gtk_label_new(dish[1].dishName);
        label1_dishPrice = gtk_label_new("60.000đ");
        image1 = gtk_image_new_from_file ("./Dish/Salmon.png");
        sprintf(quantityChar, "%d", dish[1].quantity);
        label1_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label1_dishName, "dishName");
        gtk_widget_set_name(label1_dishPrice, "dishPrice");
        gtk_widget_set_name(image1, "image");
        gtk_widget_set_name(label1_quantity, "quantity");
        gtk_grid_attach (GTK_GRID(ordersGrid), label1_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label1_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image1, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label1_quantity, 0, row, 1, 1);
        row += 2;
        
        gtk_widget_show_all (orderWindow);
    } 
    else if (dish[1].quantity > 0)
    {
        dish[1].quantity++;
        sprintf(quantityChar, "%d", dish[1].quantity);
        gtk_label_set_text(GTK_LABEL(label1_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton2_clicked(GtkButton *b)
{
    if (dish[2].quantity == 0)
    {   
        dish[2].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label2_dishName = gtk_label_new(dish[2].dishName);
        label2_dishPrice = gtk_label_new("45.000đ");
        image2 = gtk_image_new_from_file ("./Dish/ChickenFriedRice.png");
        sprintf(quantityChar, "%d", dish[2].quantity);
        label2_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label2_dishName, "dishName");
        gtk_widget_set_name(label2_dishPrice, "dishPrice");
        gtk_widget_set_name(image2, "image");  
        gtk_widget_set_name(label2_quantity, "quantity"); 
        gtk_grid_attach (GTK_GRID(ordersGrid), label2_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label2_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image2, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label2_quantity, 0, row, 1, 1);
        row += 2;
        
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[2].quantity > 0)
    {
        dish[2].quantity++;
        sprintf(quantityChar, "%d", dish[2].quantity);
        gtk_label_set_text(GTK_LABEL(label2_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton3_clicked(GtkButton *b)
{
    if (dish[3].quantity == 0)
    {   
        dish[3].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label3_dishName = gtk_label_new(dish[3].dishName);
        label3_dishPrice = gtk_label_new("45.000đ");
        image3 = gtk_image_new_from_file ("./Dish/Spaghetti.png");\
        sprintf(quantityChar, "%d", dish[3].quantity);
        label3_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label3_dishName, "dishName");
        gtk_widget_set_name(label3_dishPrice, "dishPrice");
        gtk_widget_set_name(image3, "image");   
        gtk_widget_set_name(label3_quantity, "quantity"); 
        gtk_grid_attach (GTK_GRID(ordersGrid), label3_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label3_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image3, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label3_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[3].quantity > 0)
    {   
        dish[3].quantity++;
        sprintf(quantityChar, "%d", dish[3].quantity);
        gtk_label_set_text(GTK_LABEL(label3_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton4_clicked(GtkButton *b)
{
    if (dish[4].quantity == 0)
    {   
        dish[4].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label4_dishName = gtk_label_new(dish[4].dishName);
        label4_dishPrice = gtk_label_new("50.000đ");
        image4 = gtk_image_new_from_file ("./Dish/Mussel.png");
        sprintf(quantityChar, "%d", dish[4].quantity);
        label4_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label4_dishName, "dishName");
        gtk_widget_set_name(label4_dishPrice, "dishPrice");
        gtk_widget_set_name(image4, "image");   
        gtk_widget_set_name(label4_quantity, "quantity"); 
        gtk_grid_attach (GTK_GRID(ordersGrid), label4_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label4_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image4, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label4_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[4].quantity > 0)
    {
        dish[4].quantity++;
        sprintf(quantityChar, "%d", dish[4].quantity);
        gtk_label_set_text(GTK_LABEL(label4_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton5_clicked(GtkButton *b)
{
    if (dish[5].quantity == 0)
    {
        dish[5].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label5_dishName = gtk_label_new(dish[5].dishName);
        label5_dishPrice = gtk_label_new("50.000đ");
        image5 = gtk_image_new_from_file ("./Dish/PhoBo.png");
        sprintf(quantityChar, "%d", dish[5].quantity);
        label5_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label5_dishName, "dishName");
        gtk_widget_set_name(label5_dishPrice, "dishPrice");
        gtk_widget_set_name(image5, "image");   
        gtk_widget_set_name(label5_quantity, "quantity"); 
        gtk_grid_attach (GTK_GRID(ordersGrid), label5_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label5_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image5, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label5_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[5].quantity > 0)
    {
        dish[5].quantity++;
        sprintf(quantityChar, "%d", dish[5].quantity);
        gtk_label_set_text(GTK_LABEL(label5_quantity), quantityChar); 
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton6_clicked(GtkButton *b)
{
    if (dish[6].quantity == 0)
    {   
        dish[6].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label6_dishName = gtk_label_new(dish[6].dishName);
        label6_dishPrice = gtk_label_new("50.000đ");
        image6 = gtk_image_new_from_file ("./Dish/PumpkinSoup.png");
        sprintf(quantityChar, "%d", dish[6].quantity);
        label6_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label6_dishName, "dishName");
        gtk_widget_set_name(label6_dishPrice, "dishPrice");
        gtk_widget_set_name(image6, "image");   
        gtk_widget_set_name(label6_quantity, "quantity"); 
        gtk_grid_attach (GTK_GRID(ordersGrid), label6_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label6_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image6, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label6_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[6].quantity > 0)
    {   
        dish[6].quantity++;
        sprintf(quantityChar, "%d", dish[6].quantity);
        gtk_label_set_text(GTK_LABEL(label6_quantity), quantityChar);     
        gtk_widget_show_all (orderWindow);
    }

}

void on_orderButton7_clicked(GtkButton *b)
{
    if (dish[7].quantity == 0)
    {   
        dish[7].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label7_dishName = gtk_label_new(dish[7].dishName);
        label7_dishPrice = gtk_label_new("35.000đ");
        image7 = gtk_image_new_from_file ("./Dish/Salad.png");
        sprintf(quantityChar, "%d", dish[7].quantity);
        label7_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label7_dishName, "dishName");
        gtk_widget_set_name(label7_dishPrice, "dishPrice");
        gtk_widget_set_name(image7, "image"); 
        gtk_widget_set_name(label7_quantity, "quantity");   
        gtk_grid_attach (GTK_GRID(ordersGrid), label7_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label7_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image7, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label7_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[7].quantity > 0)
    {
        dish[7].quantity++;
        sprintf(quantityChar, "%d", dish[7].quantity);
        gtk_label_set_text(GTK_LABEL(label7_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton8_clicked(GtkButton *b)
{
    if (dish[8].quantity == 0)
    {   
        dish[8].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label8_dishName = gtk_label_new(dish[8].dishName);
        label8_dishPrice = gtk_label_new("40.000đ");
        image8 = gtk_image_new_from_file ("./Dish/ApplePie.png");
        sprintf(quantityChar, "%d", dish[8].quantity);
        label8_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label8_dishName, "dishName");
        gtk_widget_set_name(label8_dishPrice, "dishPrice");
        gtk_widget_set_name(image8, "image");
        gtk_widget_set_name(label8_quantity, "quantity");   
        gtk_grid_attach (GTK_GRID(ordersGrid), label8_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label8_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image8, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label8_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow); 
    }
    else if (dish[8].quantity > 0)
    { 
        dish[8].quantity++;
        sprintf(quantityChar, "%d", dish[8].quantity);
        gtk_label_set_text(GTK_LABEL(label8_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton9_clicked(GtkButton *b)
{
    if (dish[9].quantity == 0)
    {   
        dish[9].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label9_dishName = gtk_label_new(dish[9].dishName);
        label9_dishPrice = gtk_label_new("50.000đ");
        image9 = gtk_image_new_from_file ("./Dish/EggBenedict.png");
        sprintf(quantityChar, "%d", dish[9].quantity);
        label9_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label9_dishName, "dishName");
        gtk_widget_set_name(label9_dishPrice, "dishPrice");
        gtk_widget_set_name(image9, "image");  
        gtk_widget_set_name(label9_quantity, "quantity");  
        gtk_grid_attach (GTK_GRID(ordersGrid), label9_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label9_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image9, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label9_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);
    }
    else if (dish[9].quantity > 0)
    { 
        dish[9].quantity++;
        sprintf(quantityChar, "%d", dish[9].quantity);
        gtk_label_set_text(GTK_LABEL(label9_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton10_clicked(GtkButton *b)
{
    if (dish[10].quantity == 0) 
    {
        dish[10].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label10_dishName = gtk_label_new(dish[10].dishName);
        label10_dishPrice = gtk_label_new("35.000đ");
        image10 = gtk_image_new_from_file ("./Dish/SpringRoll.png");
        sprintf(quantityChar, "%d", dish[2].quantity);
        label10_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label10_dishName, "dishName");
        gtk_widget_set_name(label10_dishPrice, "dishPrice");
        gtk_widget_set_name(image10, "image");   
        gtk_widget_set_name(label10_quantity, "quantity");  
        gtk_grid_attach (GTK_GRID(ordersGrid), label10_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label10_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image10, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label10_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[10].quantity > 0)
    { 
        dish[10].quantity++;
        sprintf(quantityChar, "%d", dish[10].quantity);
        gtk_label_set_text(GTK_LABEL(label10_quantity), quantityChar);    
        gtk_widget_show_all (orderWindow);
    }
}    

void on_orderButton11_clicked(GtkButton *b)
{
    if (dish[11].quantity == 0)  
    {
        dish[11].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label11_dishName = gtk_label_new(dish[11].dishName);
        label11_dishPrice = gtk_label_new("60.000đ");
        image11 = gtk_image_new_from_file ("./Dish/GrilledPork.png");
        sprintf(quantityChar, "%d", dish[11].quantity);
        label11_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label11_dishName, "dishName");
        gtk_widget_set_name(label11_dishPrice, "dishPrice");
        gtk_widget_set_name(image11, "image"); 
        gtk_widget_set_name(label11_quantity, "quantity");   
        gtk_grid_attach (GTK_GRID(ordersGrid), label11_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label11_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image11, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label11_quantity, 0, row, 1, 1);
        row += 2; 
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[11].quantity > 0)
    { 
        dish[11].quantity++;
        sprintf(quantityChar, "%d", dish[11].quantity);
        gtk_label_set_text(GTK_LABEL(label11_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_orderButton12_clicked(GtkButton *b)
{
    if (dish[12].quantity == 0)  
    {
        dish[12].quantity++;
        gtk_grid_insert_row (GTK_GRID(ordersGrid), row);
        label12_dishName = gtk_label_new(dish[12].dishName);
        label12_dishPrice = gtk_label_new ("70.000đ");
        image12 = gtk_image_new_from_file ("./Dish/Steak.png");
        sprintf(quantityChar, "%d", dish[12].quantity);
        label12_quantity = gtk_label_new(quantityChar);
        gtk_widget_set_name(label12_dishName, "dishName");
        gtk_widget_set_name(label12_dishPrice, "dishPrice");
        gtk_widget_set_name(image12, "image"); 
        gtk_widget_set_name(label12_quantity, "quantity");   
        gtk_grid_attach (GTK_GRID(ordersGrid), label12_dishName, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label12_dishPrice, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), image12, 0, row, 1, 1);
        gtk_grid_attach (GTK_GRID(ordersGrid), label12_quantity, 0, row, 1, 1);
        row += 2;
        gtk_widget_show_all (orderWindow);  
    }
    else if (dish[12].quantity > 0)
    { 
        dish[12].quantity++;
        sprintf(quantityChar, "%d", dish[12].quantity);
        gtk_label_set_text(GTK_LABEL(label12_quantity), quantityChar);
        gtk_widget_show_all (orderWindow);
    }
}

void on_confirmButton_clicked(GtkButton *b)
{
    sprintf(guest.ID, "%d", idGenerator());
    gtk_label_set_text(GTK_LABEL(orderNumber),(const gchar *)guest.ID);
    gtk_widget_show(orderWindow);
    gtk_widget_hide(guestWindow);
}

void on_removeButton_clicked(GtkButton *b)
{
    for (int i = 0; i <= row; i++)
    gtk_grid_remove_row(GTK_GRID(ordersGrid), i);
    for (int i = 1; i < 13; i++)
    dish[i].quantity = 0;
}

int idGenerator(){
    FILE *filepointer;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        g_print("\nidgenarate.txt failed to open...");
        fclose(filepointer);
        g_print("\nTrying to open idgenarate.txt...");
        filepointer = fopen("idgenarate.txt","w");
        fclose(filepointer);
        filepointer = fopen("idgenarate.txt", "r");
        if(filepointer == NULL){
            g_print("\nidgenarate.txt failed to open...");
            exit(EXIT_FAILURE);
        }
    }
    else{
        g_print("\nOpening idgenarate.txt...");
    }
    char temp[MAX];
    fgets(temp, sizeof(temp), filepointer);
    fseek(filepointer, 0, SEEK_END);
    int memory =  ftell(filepointer);
    fseek(filepointer, 0, SEEK_SET);
    int i = 0;
    if(memory == 0){
        i = 1;
        g_print("\nWriting mode activated.");
        fclose(filepointer);
        filepointer = fopen("idgenarate.txt", "w");
        fprintf(filepointer,"%d", i);
        g_print("\nClosing idgenarate.txt...");
        fclose(filepointer);
    }
    else{
        i = atoi(temp);
        i = i + 1;
        g_print("\nWriting mode activated.");
        fclose(filepointer);
        filepointer = fopen("idgenarate.txt", "w");
        fprintf(filepointer,"%d", i);
        g_print("\nClosing idgenarate.txt...");
        fclose(filepointer);
    }
    return i;
}

int readHistoryID(){ 
    int i = 0;
    FILE *filepointer ;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        g_print("\nCouldn't open idgenarate.txt");
        exit(EXIT_FAILURE);
    }
    else{
        g_print("\nOpening idgenarate.txt");
    }
    char temp[MAX];
    fgets(temp, sizeof(temp), filepointer);
    if(temp == NULL){
        exit(EXIT_SUCCESS);
    }
    else{
        i = atoi(temp);
    }
    g_print("\nClosing idgenarate.txt...");
    fclose(filepointer);
    return i;
}

void backupDataBase(CustomerOrderInfo a[]){
    const int temp = readHistoryID();
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfoBackup.csv", "w");
    if (filepointer == NULL){
        g_print("\nError: Could not open CustomerOrderInfoBackup.csv file");
        exit(EXIT_FAILURE);
    }
    else{
        g_print("Opening CustomerOrderInfoBackup.csv file");
    }
    int line = 0;
    fprintf(filepointer,"ID,UserName,TableNumber,Salmon,Fried Rice,Spaghetti,Mussel,Pho Bo,Pumpkin Soup,Salad,Apple Pie,Egg Benedict,Spring Roll,Grilled Pork,Beef Steak,Summarized\n");
    while(line < temp){
        fprintf(filepointer, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
        a[line].ID,
        a[line].userName,
        a[line].tableNumber,
        a[line].salmonQuantity, 
        a[line].friedRiceQuantity,
        a[line].spaghettiQuantity,
        a[line].musselQuantity,
        a[line].phoBoQuantity,
        a[line].pumpkinSoupQuantity,
        a[line].saladQuantity,
        a[line].applePieQuantity,
        a[line].eggBenedictQuantity,
        a[line].springRollQuantity,
        a[line].grilledPorkQuantity,
        a[line].beefSteakQuantity,
        a[line].summarize,
        ""
        );
        line ++;
    }
    g_print("Closing file CustomerOrderInfoBackup.csv...");
    fclose(filepointer);
}

void uploadToFile(CustomerOrderInfo a[]){
    const int temp = readHistoryID();
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "w");
    if (filepointer == NULL){
        g_print("\nERROR: Could not open file CustomerOrderInfo.csv");
        backupDataBase(a);
        exit(EXIT_FAILURE);
    }
    else{
        g_print("\nOpening CustomerOrderInfo.csv...");
    }
    int line = 0;
    fprintf(filepointer,"ID,UserName,TableNumber,Salmon,Fried Rice,Spaghetti,Mussel,Pho Bo,Pumpkin Soup,Salad,Apple Pie,Egg Benedict,Spring Roll,Grilled Pork,Beef Steak,Summarized\n");
    while (line < temp){
        fprintf(filepointer, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
        a[line].ID,
        a[line].userName,
        a[line].tableNumber,
        a[line].salmonQuantity, 
        a[line].friedRiceQuantity,
        a[line].spaghettiQuantity,
        a[line].musselQuantity,
        a[line].phoBoQuantity,
        a[line].pumpkinSoupQuantity,
        a[line].saladQuantity,
        a[line].applePieQuantity,
        a[line].eggBenedictQuantity,
        a[line].springRollQuantity,
        a[line].grilledPorkQuantity,
        a[line].beefSteakQuantity,
        a[line].summarize,
        ""
        );
        line ++;
    }
    g_print("\nClosing CustomerOrderInfo.csv file...");
    fclose(filepointer);
}

void uploadCustomerOrderData(CustomerOrderInfo a[]){
    FILE *filepointer;
    filepointer = fopen("CustomerOrderInfo.csv", "r");
    if (filepointer == NULL){
        g_print("\nError opening CSV file");
        exit(EXIT_FAILURE);
    }
    else{
        g_print("\nOpening CustomerOrderInfo.csv...");
    }

    char buf[MAX], *temp;
    int i = 0;
    fgets(buf, sizeof(buf), filepointer);
    while (fgets(buf, sizeof(buf), filepointer) != NULL) {
        temp = strtok(buf, ",");
        strcpy(a[i].ID , temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].userName, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].tableNumber, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].salmonQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].friedRiceQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].spaghettiQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].musselQuantity, temp);
        
        temp = strtok(NULL, ",");
        strcpy(a[i].phoBoQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].pumpkinSoupQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].saladQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].applePieQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].eggBenedictQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].springRollQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].grilledPorkQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].beefSteakQuantity, temp);

        temp = strtok(NULL, ",");
        strcpy(a[i].summarize, temp);
        i++;
    }
    g_print("\nClosing CustomerOrderInfo.csv");
    fclose(filepointer);
}

void moveData(guestData a, dishes b[],CustomerOrderInfo c[],int sum){ 
    int i = atoi(a.ID);
    int j = i;
    i--;
    sprintf(c[i].ID,"%d",j);
    strcpy(c[i].userName, a.guestName);
    strcpy(c[i].tableNumber, a.table);

    sprintf(c[i].salmonQuantity,"%d", b[1].quantity);
    sprintf(c[i].friedRiceQuantity,"%d",b[2].quantity);
    sprintf(c[i].spaghettiQuantity,"%d", b[3].quantity);
    sprintf(c[i].musselQuantity,"%d", b[4].quantity);
    sprintf(c[i].phoBoQuantity,"%d", b[5].quantity);
    sprintf(c[i].pumpkinSoupQuantity,"%d", b[6].quantity);
    sprintf(c[i].saladQuantity,"%d", b[7].quantity);
    sprintf(c[i].applePieQuantity,"%d",b[8].quantity);
    sprintf(c[i].eggBenedictQuantity,"%d",b[9].quantity);
    sprintf(c[i].springRollQuantity,"%d",b[10].quantity);
    sprintf(c[i].grilledPorkQuantity,"%d",b[11].quantity);
    sprintf(c[i].beefSteakQuantity,"%d",b[12].quantity);

    char summarize[128];
    sprintf(summarize,"%d",sum);
    strcpy(c[i].summarize,summarize);
    g_print("\nMove data success !!!");
    uploadToFile(c);
    g_print("\nUpload to file success !!!");
}

int calculateSummary(dishes a[],CustomerOrderInfo b[],guestData c){
    int sum = 0;
    int summarize = 0;
    char temp[128];
    for (int i = 1; i < 13; i++){
        sum = sum + (atoi(a[i].dishPrice) * a[i].quantity);
    }
    moveData(c,a,b,sum);
    return sum;
}

int totalRevenue(CustomerOrderInfo a[]){
    int sum = 0;
    for (int i = 0; i < readHistoryID(); i++){
        sum = sum + atoi(a[i].summarize);
    }
    return sum;
}

int totalDishOrdered(CustomerOrderInfo a[]){
    int total = 0;
    for(int i = 0; i < readHistoryID(); i++){
        total = total + atoi(a[i].salmonQuantity) + atoi(a[i].friedRiceQuantity) + atoi(a[i].spaghettiQuantity) + atoi(a[i].musselQuantity) + atoi(a[i].phoBoQuantity) + atoi(a[i].pumpkinSoupQuantity) + atoi(a[i].saladQuantity) + atoi(a[i].applePieQuantity) + atoi(a[i].eggBenedictQuantity) + atoi(a[i].springRollQuantity) + atoi(a[i].grilledPorkQuantity) + atoi(a[i].beefSteakQuantity);
    }
    return total;
}

int totalCustomer(){
    int i = 0;
    FILE *filepointer ;
    filepointer = fopen("idgenarate.txt", "r");
    if (filepointer == NULL){
        g_print("Couldn't open idgenarate.txt");
        exit(EXIT_FAILURE);
    }
    else{
        g_print("\nOpening idgenarate.txt");
    }
    char temp[MAX];
    fgets(temp, sizeof(temp), filepointer);
    if(temp == NULL){
        exit(EXIT_SUCCESS);
    }
    else{
        i = atoi(temp);
    }
    g_print("\nClosing idgenarate.txt...");
    fclose(filepointer);
    return i;
}

void uploadUserPass(userPass a[]){
    FILE *filepointer;
    filepointer = fopen("UserPass.csv", "r");
    if(filepointer == NULL){
        g_print("\nCouldn't open userPass.txt");
        exit(EXIT_FAILURE);
    }
    else{
        g_print("\nUploading userPass...");
    }
    char buf[MAX], *temp;
    int i = 0;
    fgets(buf, sizeof(buf), filepointer);
    while(fgets(buf, sizeof(buf), filepointer) != NULL){
        temp = strtok(buf,",");
        strcpy(a[i].userName, temp);

        temp = strtok(NULL,",");
        strcpy(a[i].passWord,temp);

        i++;
    }
    g_print("\nUpload success, closing userPass.csv file...");
    fclose(filepointer);
}

int checkNamePass(userPass a[],char userName[], char password[]){
    int result = 1;
    FILE *filepointer;
    filepointer = fopen("UserPass.csv", "r");
    if(filepointer == NULL){
        g_print("\nError: Could not open");
        exit(EXIT_FAILURE);
    }
    else{
        g_print("\nOpening UserPass.csv file...");
    }
    char buf[MAX];
    int j = 0;
    while(fgets(buf, sizeof(buf), filepointer) != NULL){
        j++;
    }
    j--;
    g_print("\nClosing UserPass.csv file...");
    fclose(filepointer);
    for (int i = 0; i < j; i++){
        if(strcmp(userName,a[i].userName) == 0 && strcmp(password,a[i].passWord) == 0){
            result = 0;
            break;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {

    gtk_init(&argc, &argv);
    cssInsertion();
    uploadCustomerOrderData(customers);
    uploadUserPass(adminLogin);
    // orderWindowUI();
    // dashboardUI();
    loginUI();
    managerLoginUI();
    // guestWindowUI();
    

    gtk_main();
    return EXIT_SUCCESS;
}

