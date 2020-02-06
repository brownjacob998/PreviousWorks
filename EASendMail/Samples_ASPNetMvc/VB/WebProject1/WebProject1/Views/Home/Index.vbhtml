﻿@Code
    ViewBag.Title = "EASendMail MVC Samples"
End Code

<div class="jumbotron">
    <h1>EASendMail SMTP Component</h1>
    <p class="lead">
        Send email in ASP, VB, VBA, VC++, C++/CLI, C#, VB.NET, JavaScript, ASP.NET,
        Delphi or other COM/.NET environment applications based on SMTP, Exchange Web Service (EWS)
        or WebDAV protocols. SSL, TLS, S/MIME, Gmail OAUTH, Live OAUTH, HTML and Embedded Images are supported.
    </p>
    <p><a href="https://www.emailarchitect.net/easendmail" target="_blank" class="btn btn-primary btn-lg">Learn more &raquo;</a></p>
</div>

<div>
    <h2>ASP.NET MVC Samples</h2>
</div>
<div class="row">
    <div class="col-md-3">
        <h2>Simple</h2>
        <p>
            Send a simple email from MVC with form post or ajax.
        </p>
        <p>
            @Html.ActionLink("Try now", "Index", "SimpleMail", Nothing, New With {.class = "btn btn-default"})
        </p>
    </div>

    <div class="col-md-3">
        <h2>Google Oauth</h2>
        <p>Send email with Gmail XOAUTH2 authentication.</p>
        <p>
            @Html.ActionLink("Try now", "Index", "GmailOauth", Nothing, New With {.class = "btn btn-default"})
        </p>
    </div>

    <div class="col-md-3">
        <h2>Mutiple Threads</h2>
        <p>Send mass emails with background threads.</p>
        <p>
            @Html.ActionLink("Try now", "Index", "Mass", Nothing, New With {.class = "btn btn-default"})
        </p>
    </div>

    <div class="col-md-3">
        <h2>Advanced Queue With Database</h2>
        <p> Send email from ASP.NET MVC with Thread Pool and Database Integration</p>
        <p>
            @Html.ActionLink("Try now", "Index", "DbRecipients", Nothing, New With {.class = "btn btn-default"})
        </p>
    </div>
</div>