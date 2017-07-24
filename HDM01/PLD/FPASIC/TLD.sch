<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="xc9500xl" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="pha" />
        <signal name="phb" />
        <signal name="clock" />
        <signal name="ticks" />
        <signal name="direction" />
        <signal name="XLXN_1" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_7" />
        <signal name="DATA" />
        <port polarity="Input" name="pha" />
        <port polarity="Input" name="phb" />
        <port polarity="Input" name="clock" />
        <port polarity="Output" name="ticks" />
        <port polarity="Output" name="direction" />
        <port polarity="Output" name="DATA" />
        <blockdef name="encoder">
            <timestamp>2017-7-24T17:46:0</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="fd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <rect width="256" x="64" y="-320" height="256" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="buf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-64" y2="0" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="128" />
            <line x2="128" y1="0" y2="-32" x1="64" />
        </blockdef>
        <block symbolname="encoder" name="XLXI_1">
            <blockpin signalname="pha" name="rotary_a" />
            <blockpin signalname="phb" name="rotary_b" />
            <blockpin signalname="clock" name="clk" />
            <blockpin signalname="ticks" name="detent" />
            <blockpin signalname="direction" name="dir" />
        </block>
        <block symbolname="fd" name="XLXI_2">
            <blockpin signalname="ticks" name="C" />
            <blockpin signalname="XLXN_3" name="D" />
            <blockpin signalname="XLXN_1" name="Q" />
        </block>
        <block symbolname="inv" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="I" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_4">
            <blockpin signalname="XLXN_1" name="I" />
            <blockpin signalname="DATA" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="592" y="560" name="XLXI_1" orien="R0">
        </instance>
        <branch name="pha">
            <wire x2="592" y1="400" y2="400" x1="560" />
        </branch>
        <iomarker fontsize="28" x="560" y="400" name="pha" orien="R180" />
        <branch name="phb">
            <wire x2="592" y1="464" y2="464" x1="560" />
        </branch>
        <iomarker fontsize="28" x="560" y="464" name="phb" orien="R180" />
        <branch name="clock">
            <wire x2="592" y1="528" y2="528" x1="560" />
        </branch>
        <iomarker fontsize="28" x="560" y="528" name="clock" orien="R180" />
        <branch name="ticks">
            <wire x2="992" y1="400" y2="400" x1="976" />
            <wire x2="992" y1="400" y2="720" x1="992" />
            <wire x2="1328" y1="720" y2="720" x1="992" />
            <wire x2="1504" y1="720" y2="720" x1="1328" />
            <wire x2="1328" y1="496" y2="496" x1="1248" />
            <wire x2="1248" y1="496" y2="624" x1="1248" />
            <wire x2="1328" y1="624" y2="624" x1="1248" />
            <wire x2="1328" y1="624" y2="720" x1="1328" />
        </branch>
        <branch name="direction">
            <wire x2="1008" y1="528" y2="528" x1="976" />
        </branch>
        <iomarker fontsize="28" x="1008" y="528" name="direction" orien="R0" />
        <instance x="1328" y="624" name="XLXI_2" orien="R0" />
        <branch name="XLXN_3">
            <wire x2="1312" y1="224" y2="368" x1="1312" />
            <wire x2="1328" y1="368" y2="368" x1="1312" />
            <wire x2="2176" y1="224" y2="224" x1="1312" />
            <wire x2="2176" y1="224" y2="480" x1="2176" />
            <wire x2="2176" y1="480" y2="480" x1="2112" />
        </branch>
        <iomarker fontsize="28" x="1504" y="720" name="ticks" orien="R0" />
        <instance x="1888" y="512" name="XLXI_3" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1728" y1="368" y2="368" x1="1712" />
            <wire x2="1728" y1="368" y2="480" x1="1728" />
            <wire x2="1888" y1="480" y2="480" x1="1728" />
            <wire x2="1728" y1="480" y2="608" x1="1728" />
            <wire x2="1888" y1="608" y2="608" x1="1728" />
        </branch>
        <instance x="1888" y="640" name="XLXI_4" orien="R0" />
        <branch name="DATA">
            <wire x2="2384" y1="608" y2="608" x1="2112" />
        </branch>
        <iomarker fontsize="28" x="2384" y="608" name="DATA" orien="R0" />
    </sheet>
</drawing>