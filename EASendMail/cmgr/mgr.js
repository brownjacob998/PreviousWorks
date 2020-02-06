// JScript source code
var menus = ['menu_1', 'menu_2', 'menu_3', 'menu_4', 'menu_5', 'menu_6'];
var installdir = "";

function resizemenu() {
    var vw = 800;
    if ($(window).width() < 800) {
        $('#page').css({ 'width': vw });
        $('#header').css({ 'width': vw });
    }
    else {
        $('#page').css({ 'width': $(window).width() });
        $('#header').css({ 'width': $(window).width() - 22 });
    }

  /*  if ($('#content_3').css('display') != "none") {
        var cw = $('#page').width() - $('#menu').width() - 15;
        $('#content_3 div.content_desc').css({ 'width': cw });
    }

    if ($('#content_4').css('display') != "none") {
        var cw = $('#page').width() - $('#menu').width() - 15;
        $('#content_4 div.content_desc').css({ 'width': cw });
    }
    */

    var vheadr = $('#header').height() + 20;
    var vh = $('#content').height();
    if (vh < $(window).height() - vheadr) {
        vh = $(window).height() - vheadr;
    }
    else {
        vh += 10;
    }
    $('#menu').css({ 'height': vh });
}

function displaycontent(menuid) {
    hide_sysinfo();
    var contents = ['content_1', 'content_2', 'content_3', 'content_4', 'content_5', 'content_6'];
    var index = 0;

    for (var i = 0; i < menus.length; i++) {
        if (menuid == menus[i]) {
            index = i;
            $('#' + menus[i]).removeClass();
            $('#' + menus[i]).addClass('menu_selected');
        }
        else {

            $('#' + menus[i]).removeClass();
            $('#' + menus[i]).addClass('link_menu');
        }
    }

    for (var i = 0; i < contents.length; i++) {
        if (i != index)
            $('#' + contents[i]).hide();
    }

    $('#' + contents[index]).show();

    if (index == 0) {
        $('#startmenu').unbind();
        $('#startmenu div a').click(function (event) {
            event.preventDefault();
            var v = this.id;
            if (v == 'sub_menu1') {
                displaycontent('menu_2');
            }
            else if (v == 'sub_menu2') {
                displaycontent('menu_3');
            }
            else if (v == 'sub_menu3') {
                displaycontent('menu_4');
            }
            else if (v == 'sub_menu4') {
                displaycontent('menu_5');
            }
        });

    }
    
    resizemenu();
}

$(function () {

    if ($.browser.msie && $.browser.version.substr(0, 1) < 7 && $.browser.version.substr(0, 1) > 2) {
        $('button').live('mouseover', function () {
            $(this).removeClass('button');
            $(this).addClass('button_hover');
        });

        $('button').live('mouseout', function () {
            $(this).removeClass('button_hover');
            $(this).addClass('button');
        });

        $('#content').css('margin-top', '0px');
        $('#sysinfo').css("position", 'absolute');
        $('#sysinfo').css("top", '0px');

        $(window).unbind('scroll');
        $(window).scroll(function (event) {
            $('#sysinfo').css("top", $(window).scrollTop());
        });
    }
    else {
        $('#header').css('width', '100%');
    }

    $(document).bind("contextmenu", function (e) {
        activeObj = document.activeElement;
        if (activeObj.tagName.toUpperCase() == "INPUT" || activeObj.tagName.toUpperCase() == "TEXTAREA") {
            return true;
        }
        return false;
    });

    var year = new Date().getFullYear();
    $('#copyright_year').text('2004-' + year);
    
    resizemenu();
    $(window).resize(function (event) {
        resizemenu();
    });

    installdir = document.location.href;

    installdir = installdir.substr(8); // remove file:///
    installdir = installdir.replace(/\//g, "\\");

    var pos = installdir.lastIndexOf("\\");
    if (pos != -1) {
        installdir = installdir.substr(0, pos);
    }
    pos = installdir.lastIndexOf("\\");
    if (pos != -1) {
        installdir = installdir.substr(0, pos);
    }
    installdir = decodeURI(installdir);

    displaycontent(menus[0]);

    for (var i = 0; i < menus.length; i++) {
        $('#' + menus[i]).click(function (event) {
            event.preventDefault();
            displaycontent(this.id);
        });
    }

    init_inputhelper();

    $('#showDoc').click(function (e) {
        e.preventDefault();
        var WshShell = new ActiveXObject("WScript.Shell");
        var doc = installdir + "\\easendmail.chm";
        WshShell.Run("hh.exe \""+ doc + "\"", 3);
    });

    $('#doc_svc_variables').click(function (e) {
        e.preventDefault();
        var WshShell = new ActiveXObject("WScript.Shell");
        var doc = installdir + "\\easendmail.chm::/html/svc_variables.htm";
        WshShell.Run("hh.exe \"" + doc + "\"", 3);
    });


    $('#uninstall').click(function (e) {
        e.preventDefault();
        try {
            var WshShell = new ActiveXObject("WScript.Shell");
            var installer = installdir + "\\uninst.exe";
            WshShell.Run("\"" + installer + "\"");
        } catch (e)
        { }
    });

});

function init_inputhelper() {

    $('.autoc a').live('click', function (event) {
        event.preventDefault();

        var v = trim($(this).text(), " \r\n");
        v = v.replace("\r\n", "");

        var obj = $(this).parent().parent().find('input:text, textarea');

        if ($(obj).length == 0)
            return;

        if ($(obj).attr("type") == "text") {
            var oldv = $(obj).val();
            var newv = v;
            newv += ", ";
            newv += oldv;
            newv = trim(newv, ", ");
            $(obj).val(newv);
            $(obj).focus();
        }
        else {
            var oldv = $(obj).val();
            var newv = v;
            newv += "\r\n";
            newv += oldv;
            newv = trim(newv, "\r\n");
            $(obj).val(newv);
            $(obj).focus();

        }
    });
}

function trim(src, trimer) {
    var len = src.length;
    var i = 0;
    if (len > 0) {
        for (i = 0; i < len; i++) {
            var ch = src.charAt(i);
            if (trimer.indexOf(ch) == -1) {
                break;
            }
        }
        src = src.substr(i);
    }

    len = src.length;
    if (len > 0) {
        for (i = len - 1; i >= 0; i--) {
            var ch = src.charAt(i);
            if (trimer.indexOf(ch) == -1) {
                break;
            }
        }

        src = src.substr(0, i + 1);
    }
    return src;
}

function show_load() {
    hide_load();
    var maskHeight = $(document).height();
    var maskWidth = $(window).width();

    $('#dg_mask').css({ 'width': maskWidth, 'height': maskHeight });

    $('#dg_mask').fadeIn(100);
    $('#dg_mask').fadeTo("fast", 0.8);

    var winH = $(window).height();
    var winW = $(window).width();

    $('#loading').css('top', 200 + $(window).scrollTop());
    $('#loading').css('left', 470);

    $('#loading').fadeIn(200);
}

function show_update() {

    var maskHeight = $(document).height();
    var maskWidth = $(window).width();

    $('#dg_mask').hide();
    $('#update_mask').css({ 'width': maskWidth, 'height': maskHeight });

    $('#update_mask').fadeIn(100);
    $('#update_mask').fadeTo("fast", 0.1);

    $('#loading').css('top', 200 + $(window).scrollTop());
    $('#loading').css('left', 470);
    $('#loading').fadeIn(200);

}

function hide_load() {
    $('#update_mask').hide();
    $('#dg_mask').hide();
    $('#loading').hide();
    $('#s_dg').hide();
}

function hide_update() {
    $('#s_dg').hide();
    $('#dg_mask').hide();
    $('#update_mask').hide();
    $('#loading').fadeOut(500);
}

function loading_codeex() {
    return '<div class="div_loading" ><img src="loading.gif" /></div>';
}

function loading_code() {
    var wh = $(window).height() - 100;
    return '<div class="div_loading" style="height:' + wh + 'px;"><img src="loading.gif" /></div>';
}

function selectOption(select_id, option_val) {
    $(select_id + ' option:selected').removeAttr('selected');
    $(select_id + ' option[value=' + option_val + ']').attr('selected', 'selected');
}

function createTips(obj_id, tips) {
    var v = "<div class=\"tips\"><div class=\"tips_content\"><span class=\"alert-icon\"></span>";
    v += tips;
    v += "</div><div><img src=\"tips.gif\" class=\"tips_image\" alt=\"\"/></dv></div>";

    $(obj_id).parent().find('div.tips').remove();

    if (tips == "")
        return;

    $(obj_id).after(v);
    var vleft = $(obj_id).offset().left + $(obj_id).width() - 15;
    if (vleft + $(obj_id).next().width() > $(window).width()) {
        vleft = $(window).width() - $(obj_id).next().width();
    }

    var vheight = $(obj_id).next().height();

    var vtop = $(obj_id).offset().top - vheight + 7;
    if ($(window).scrollTop() > vtop) {
        $(window).scrollTop(vtop - 10);
    }

    if (vtop + vheight > $(window).height() + $(window).scrollTop()) {
        var scrTop = vtop + vheight - $(window).height();
        $(window).scrollTop(scrTop + 30);
    }

    $(obj_id).next().offset({ top: vtop, left: vleft });
    $(obj_id).next().show();

}

function show_sysinfo(bloading) {
    if (bloading) {
        $('#sysretry').hide();
        $('#sysloading').show();
    }
    else {
        $('#sysloading').hide();
        $('#sysretry').show();
    }

    var maskWidth = $(window).width();

    $('#sysinfo').css("width", maskWidth);
    $('#sysinfo').css("top", $(window).scrollTop());
    $('#sysinfo').show();

    $(window).unbind('scroll');
    $(window).scroll(function (event) {
        $('#sysinfo').css("top", $(window).scrollTop());
    });
}

function hide_sysinfo() {
    $('#sysinfo').hide();
}

function verify_number(obj_id) {
    var v = $(obj_id).val();
    if (!val_isnumber(v)) {

        createTips(obj_id, "The value you just input MUST be an unsigned integer!");
        return;
    }

    var min_v = $(obj_id).parent().find('div input.min_val').val();
    var max_v = $(obj_id).parent().find('div input.max_val').val();

    if (v * 1 < min_v || v * 1 > max_v) {
        createTips(obj_id, $(obj_id).parent().find('div.numberlimit').text());
    }
    else {
        createTips(obj_id, "");
    }
}

function val_isnumber(src) {
    var search = "0123456789";
    var len = src.length;
    if (len == 0)
        return false;

    for (var i = 0; i < len; i++) {
        var ch = src.charAt(i);
        if (search.indexOf(ch) == -1) {
            return false;
        }
    }
    return true;
}