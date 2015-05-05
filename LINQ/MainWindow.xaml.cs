using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LINQ
{
    public class ImageDesc
    {
        public string Path { get; set; }
    }

    public class Sprite
    {
        public ImageDesc Image { get; set; }

        public Point Position { get; set; }

        public Point Size { get; set; }
    }

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {




        public MainWindow()
        {
            InitializeComponent();
        }
    }
}
