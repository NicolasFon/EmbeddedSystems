<?php
        if($_POST['executer'] == 'LedOn')
        {
                exec('/home/pi/EmbeddedSystems/GPIOLed 25 1');
        }
        if($_POST['executer'] == 'LedOff')
        {
                exec('/home/pi/EmbeddedSystems/GPIOLed 25 0');
        }
        if($_POST['executer'] == 'SwingCradle')
        {
                 exec('python /home/pi/EmbeddedSystems/ServoProjet.py');
        }
        if($_POST['executer'] == 'Music')
        {
                 exec('mpg321 /home/pi/EmbeddedSystems/0999.mp3');
        }
        header('Location: Projet.php');
?>
