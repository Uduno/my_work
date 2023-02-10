import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Température extends JFrame{
    private JPanel Température;
    private JButton backButton;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private JTextField textField1;
    private JTextField textField2;
    private JButton convertirButton;
    private JButton effacerButton;

    public  Température(){
        add(Température);
        setSize(400,400);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        backButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Température.setVisible(false);
                new Acceuil().setVisible(true);
            }
        });
        String s1[] = {"Celcius(°C)","Fahrenheit(°F)","Kelvin(K)","Rankine(°R)","Réaumur(°Re)"};
        for (int i=0; i < s1.length;i++){
            comboBox1.addItem(s1[i]);
            comboBox2.addItem(s1[i]);
        }
    }

    public static double Tmpm(String m, String m2, double d1){
        switch (m){
            case "Celcius(°C)":
                switch (m2){
                    case "Celcius(°C)":
                        return d1;
                    case "Fahrenheit(°F)":
                        return (d1-32)*5/9;
                    case "Kelvin(K)":
                        return d1-273.15;
                    case "Rankine(°R)":
                        return (d1 - 491.67)/1.8;
                    case "Réaumur(°Re)":
                        return d1*0.8;
                    default:
                        break;
                }
            case "Fahrenheit(°F)":
                switch (m2){
                    case "Celcius(°C)":
                        return d1*(9/8)+32;
                    case "Fahrenheit(°F)":
                        return d1;
                    case "Kelvin(K)":
                        return (d1 -273.15) * 9/5 + 32;
                    case "Rankine(°R)":
                        return (d1 - 491.67) + 32;
                    case "Réaumur(°Re)":
                        return d1 * 2.25 + 32;
                    default:
                        break;
                }
            case "Kelvin(K)":
                switch (m2){
                    case "Celcius(°C)":
                        return d1+273.15;
                    case "Fahrenheit(°F)":
                        return ((d1 - 32)*5/9+273.15);
                    case "Kelvin(K)":
                        return d1;
                    case "Rankine(°R)":
                        return ((d1- 491.67)/1.8)+273.15;
                    case "Réaumur(°Re)":
                        return (d1/0.8)+273.15;
                    default:
                        break;
                }
            case "Rankine(°R)":
                switch (m2){
                    case "Celcius(°C)":
                        return d1 * 1.8+ 491.67;
                    case "Fahrenheit(°F)":
                        return (d1 - 32)+ 491.67;
                    case "Kelvin(K)":
                        return (d1 - 273.15)* 1.8+ 491.67;
                    case "Rankine(°R)":
                        return d1;
                    case "Réaumur(°Re)":
                        return d1 * 2.25 + 491.67;
                    default:
                        break;
                }
            case "Réaumur(°Re)":
                switch (m2){
                    case "Celcius(°C)":
                        return d1/0.8;
                    case "Fahrenheit(°F)":
                        return (d1 - 32)* 0.44444;
                    case "Kelvin(K)":
                        return (d1 - 273.15)* 0.8;
                    case "Rankine(°R)":
                        return (d1 - 491.67)* 0.44444;
                    case "Réaumur(°Re)":
                        return d1;
                    default:
                        break;
                }
            default:
                break;
        }
        return -1;
    }
    public static void main(String[] args){
        Température t = new Température();
        Num num = new Num();
        JButton btn = t.convertirButton;
        JButton clear = t.effacerButton;


        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String n1 =  t.textField1.getText();
                String n2 = t.textField2.getText();
                JComboBox c1 = t.comboBox1;
                JComboBox c2 = t.comboBox2;
                String cnv1;
                String cnv2;
                if(!n1.isEmpty()){
                    if (!num.isNumeric(n1)){
                        t.textField1.setText("Null");
                        t.textField2.setText("Null");
                        return;
                    }else{
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        System.out.println(cnv1);

                        double rslt = Tmpm(cnv1,cnv2,Double.valueOf(n1));
                        t.textField2.setText(Double.toString(rslt));
                    }

                } else if (n1.isEmpty() && !n2.isEmpty()) {
                    if (!num.isNumeric(n2)){
                        t.textField1.setText("Null");
                        t.textField2.setText("Null");
                        return;
                    }else {
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        double rslt = Tmpm(cnv2,cnv1,Double.valueOf(n2));;
                        t.textField1.setText(Double.toString(rslt));
                    }
                }


            }
        });
        clear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                t.textField1.setText("");
                t.textField2.setText("");
            }
        });
    }
}
