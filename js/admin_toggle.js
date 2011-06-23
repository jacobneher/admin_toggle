(function ($) {
  Drupal.behaviors.quickbar = {
  attach: function (context, settings) {
    $('.admin-toggle-admin-tabs').click(function() {
      if ($(this).hasClass('active')) {
        $(this).removeClass('active');
        $('div.tabs').css('display', 'none');
      }
      else {
        $(this).addClass('active');
        $('div.tabs').css('display', 'block');
      }
    });
    
    $('.admin-toggle-messages').click(function() {
      if ($(this).hasClass('active')) {
        $(this).removeClass('active');
        $('div.messages').css('display', 'none');
      }
      else {
        $(this).addClass('active');
        $('div.messages').css('display', 'block');
      }
    });
    
    $('body.admin-toggle-tabs-hover #region-content').hover(
      function() {
        $('div.tabs').fadeIn('fast');
      },
      function() {
        $('div.tabs').fadeOut('fast');
      }
    );
    
    // Block handling
    $('body.admin-toggle-tabs-hover .block').hover(
      function() {
        $('.block-admin-wrapper', this).fadeIn('fast');
      },
      function() {
        $('.block-admin-wrapper', this).fadeOut('fast');
      }
    );
  }
  }
})(jQuery);