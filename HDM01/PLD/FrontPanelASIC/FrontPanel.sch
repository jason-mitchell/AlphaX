<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="xc9500xl" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="PHA" />
        <signal name="PHB" />
        <signal name="ECLK" />
        <signal name="IRQ" />
        <signal name="DIR" />
        <signal name="XLXN_15" />
        <signal name="DB(7:0)" />
        <signal name="SCLK" />
        <signal name="MOSI" />
        <port polarity="Input" name="PHA" />
        <port polarity="Input" name="PHB" />
        <port polarity="Input" name="ECLK" />
        <port polarity="Output" name="IRQ" />
        <port polarity="Output" name="DIR" />
        <port polarity="Output" name="DB(7:0)" />
        <port polarity="Input" name="SCLK" />
        <port polarity="Input" name="MOSI" />
        <blockdef name="rotary_decoder">
            <timestamp>2017-8-1T20:24:40</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="ibuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <blockdef name="obuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
        </blockdef>
        <blockdef name="spi">
            <timestamp>2017-8-9T15:23:2</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <block symbolname="rotary_decoder" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="rotary_a" />
            <blockpin signalname="XLXN_2" name="rotary_b" />
            <blockpin signalname="XLXN_15" name="clk" />
            <blockpin signalname="XLXN_4" name="detent" />
            <blockpin signalname="XLXN_5" name="dir" />
        </block>
        <block symbolname="ibuf" name="XLXI_3">
            <blockpin signalname="PHA" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_4">
            <blockpin signalname="PHB" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_5">
            <blockpin signalname="ECLK" name="I" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_6">
            <blockpin signalname="XLXN_4" name="I" />
            <blockpin signalname="IRQ" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_7">
            <blockpin signalname="XLXN_5" name="I" />
            <blockpin signalname="DIR" name="O" />
        </block>
        <block symbolname="spi" name="XLXI_14">
            <blockpin signalname="SCLK" name="SCLK" />
            <blockpin signalname="MOSI" name="MOSI" />
            <blockpin signalname="DB(7:0)" name="PDOUT(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="624" y="480" name="XLXI_2" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="624" y1="320" y2="320" x1="592" />
        </branch>
        <instance x="368" y="352" name="XLXI_3" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="624" y1="384" y2="384" x1="592" />
        </branch>
        <instance x="368" y="416" name="XLXI_4" orien="R0" />
        <instance x="368" y="480" name="XLXI_5" orien="R0" />
        <branch name="XLXN_4">
            <wire x2="1040" y1="320" y2="320" x1="1008" />
        </branch>
        <instance x="1040" y="352" name="XLXI_6" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="1040" y1="448" y2="448" x1="1008" />
        </branch>
        <instance x="1040" y="480" name="XLXI_7" orien="R0" />
        <branch name="PHA">
            <wire x2="368" y1="320" y2="320" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="320" name="PHA" orien="R180" />
        <branch name="PHB">
            <wire x2="368" y1="384" y2="384" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="384" name="PHB" orien="R180" />
        <branch name="ECLK">
            <wire x2="368" y1="448" y2="448" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="448" name="ECLK" orien="R180" />
        <branch name="IRQ">
            <wire x2="1296" y1="320" y2="320" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1296" y="320" name="IRQ" orien="R0" />
        <branch name="DIR">
            <wire x2="1296" y1="448" y2="448" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1296" y="448" name="DIR" orien="R0" />
        <text style="fontsize:24;fontname:Arial" x="104" y="520">CLOCK: 500Hz from ARM Cortex SysTick</text>
        <branch name="XLXN_15">
            <wire x2="608" y1="448" y2="448" x1="592" />
            <wire x2="624" y1="448" y2="448" x1="608" />
            <wire x2="608" y1="448" y2="816" x1="608" />
            <wire x2="720" y1="816" y2="816" x1="608" />
        </branch>
        <instance x="560" y="1104" name="XLXI_14" orien="R0">
        </instance>
        <branch name="DB(7:0)">
            <wire x2="976" y1="1008" y2="1008" x1="944" />
        </branch>
        <iomarker fontsize="28" x="976" y="1008" name="DB(7:0)" orien="R0" />
        <branch name="SCLK">
            <wire x2="560" y1="1008" y2="1008" x1="528" />
        </branch>
        <iomarker fontsize="28" x="528" y="1008" name="SCLK" orien="R180" />
        <branch name="MOSI">
            <wire x2="560" y1="1072" y2="1072" x1="528" />
        </branch>
        <iomarker fontsize="28" x="528" y="1072" name="MOSI" orien="R180" />
    </sheet>
</drawing>